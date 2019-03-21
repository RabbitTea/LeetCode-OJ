/*
* @Description：单链表逆置；关键是为了不掉链，需要使用三个节点指针，分别指向
                当前节点，前一个节点和后一个节点；在断掉当前节点的next转化为
				链接前一个节点时，需要保存原来的next节点。
*/

#include <iostream>

using namespace std;

//定义单链表节点结构体
struct ListNode {
	int val;
	ListNode* next;

public:
	//构造函数
	ListNode(int value) {
		val = value;
		next = NULL;
	}

	//插入单链表，包含输入过程
	ListNode* insertList() {
		
		int value;
		
		cout << "请输入链表中的值：" << endl;
		//头节点赋值
		cin >> value;
		ListNode* head = new ListNode(value);

		//插入节点
		ListNode* p = head;
		while (cin >> value) {
			ListNode* newNode = new ListNode(value);  //创建新节点
			p->next = newNode;  //链接

			p = p->next;  //后移

			if (cin.get() == '\n') {  //获取到换行符直接退出
				break;
			}
		}

		return head;
	}

	//输出单链表中的值
	void traversePrint(ListNode* head) {
		ListNode* p = head;

		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
};


//单链表逆置算法
ListNode* reverseLinkedList(ListNode* head) {
	ListNode* prev = head;
	ListNode* cur = head->next;  //从第二个节点开始处理
	ListNode* next = NULL;

	while (cur) {  //cur为空，即cur指向链表尾节点的后一个节点时退出循环
		next = cur->next;   //先保存当前处理节点的原始next域，即保证不断链
		cur->next = prev;  //逆转当前节点
		
		//后移
		prev = cur;
		cur = next;
	}

	head->next = NULL;
	head = prev;    //让原来的尾成为头

	return head;
}


int main() {

	//构造单链表
	ListNode* head = NULL;
	head = head->insertList();
	//head->traversePrint(head);

	//链表逆置
	head = reverseLinkedList(head);

	//输出
	cout << "逆置后的结果为：" << endl;
	head->traversePrint(head);
}