/*
 * @idea: ע��һ�������ߵ����ʱֱ�������һ������ʣ�µ�ȫ��Ԫ�ؼ���
 * @author�� SA18225018
 * @date�� 2018/11/14
 */
package examination4;

import java.util.ArrayList;
import java.util.Scanner;

public class MergeTwoList {

	public static void main(String[] args) {
		ArrayList<Integer> arr1 = new ArrayList<>();
		ArrayList<Integer> arr2 = new ArrayList<>();
		
		System.out.println("�������һ���������е�Ԫ��ֵ��");
		Scanner l1 = new Scanner(System.in);
		while(!l1.hasNext("q")) {  // ���뵥�����Ԫ��ֵ���������ַ�q���˳�
			arr1.add(Integer.valueOf(l1.next()));  //  ��Ԫ��ֵ��ӵ���̬������
		}
		//����������1
		ListNode head1 = new ListNode(0);
		head1 = head1.create(head1, arr1);
		
		System.out.println("������ڶ����������е�Ԫ��ֵ��");
		Scanner l2 = new Scanner(System.in);
		while(!l2.hasNext("q")) {  // ���뵥�����Ԫ��ֵ���������ַ�q���˳�
			arr2.add(Integer.valueOf(l2.next()));  
		}
		//����������2
		ListNode head2 = new ListNode(0);
		head2 = head2.create(head2, arr2);
		
		//�õ��ϲ���ĵ�����
		ListNode newlist = MergeTwoList.MergeLists(head1, head2);
        
		//���
		System.out.println("�ϲ���ĵ�����Ϊ:");
		ListNode p = newlist;
		while(p != null){
			System.out.print(p.val + " ");
			p = p.next;
		}
	}
	
	public static ListNode MergeLists(ListNode l1, ListNode l2) {
		ListNode newhead = new ListNode(0); // �����������ͷ�ڵ�
		ListNode p = newhead;
		
		while (l1 != null || l2 != null) {
			if(l1 !=null && l2 != null) {
				if(l1.val <= l2.val) {
					p.next = l1;
					l1 = l1.next;
				}else {
					p.next = l2;
					l2 = l2.next;
				}
				p = p.next;
			}else if(l1 == null) {
				p.next = l2;
				break;
			}else if(l2 == null) {
				p.next = l1;
				break;
			}
		}
		
		return newhead.next;
	}

}
