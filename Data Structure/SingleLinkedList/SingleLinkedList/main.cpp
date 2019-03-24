/*
* 数据结构：单链表的实现
*/

#include <iostream>

using namespace std;

//定义链表节点结构体
struct ListNode {
	int val;
	ListNode* next;

	ListNode(int value) {
		val = value;
		next = NULL;
	}
};


//定义链表结构体
//不带头结点
struct SingleList {
	ListNode* head = NULL;

	//创建单链表：直接输入
	void list_create() {
		int value;
		ListNode* p = NULL;
		
		while (cin >> value) {
			if (head == NULL) {
				head = new ListNode(value);    //△注意这里一开始head为NULL，不能直接令head->val = value，否则会报空指针异常
				p = head;     //p应该在这里赋值，否则p会一直为空；
			}
			else {
				ListNode* newNode = new ListNode(value);
				p->next = newNode;

				p = p->next;
			}

			if (cin.get() == '\n') {
				break;
			}
		}
		
	}

	//单链表的尾插法
	void list_insert(int value) {
		if (head == NULL) {
			head = new ListNode(value);
		}

		ListNode* p = head;
		while (p != NULL) {
			ListNode* newNode = new ListNode(value);
			p->next = newNode;
			p = p->next;
		}

		//return head;
	}

	//单链表的删除：删除指定值的所有节点；返回删除后的链表
	ListNode* list_remove(int x) {
		//因为不带头结点，所以不好删除；这里新添加一个结点，作为整个链表的头部
		ListNode* first = new ListNode(-1);
		first->next = head;

		ListNode* p = first;

		while (p->next != NULL) {  //循环到倒数第二个节点
			if (p->next->val == x) {
				ListNode* q = p->next;   //保存要删除的结点
				p->next = p->next->next;  //把要删除的后一个节点链接到前一个节点的next域
				delete q;   //释放内存
			}
			p = p->next;  //后移
		}

		return head;
	}

	//单链表的遍历输出
	void list_traverse() {
	
		ListNode* p = head;

		while (p != NULL) {
			
			cout << p->val << " ";
			p = p->next;
		}
	}
};

int main()
{
	//建立单链表
	int value;
	SingleList list;    //△这里建立的是SingleList结构体的对象，而用new返回的是指向该结构体的指针
	//对象调用结构体中的方法用.即可，而指针调用需要->
	cout << "请输入链表中的值：" << endl;
	/*
	while (cin >> value) {
		list.list_insert(value);

		if (cin.get() == '\n') {
			break;
		}
	}
	*/

	list.list_create();

	//输出单链表
	cout << "原单链表为：" << endl;
	list.list_traverse();

	//删除值为x的节点
	list.list_remove(3);

	//输出删除后的单链表
	cout << "删除后的单链表为：" << endl;
	list.list_traverse();
}