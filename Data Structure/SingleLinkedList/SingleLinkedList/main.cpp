/*
* ���ݽṹ���������ʵ��
*/

#include <iostream>

using namespace std;

//��������ڵ�ṹ��
struct ListNode {
	int val;
	ListNode* next;

	ListNode(int value) {
		val = value;
		next = NULL;
	}
};


//��������ṹ��
//����ͷ���
struct SingleList {
	ListNode* head = NULL;

	//����������ֱ������
	void list_create() {
		int value;
		ListNode* p = NULL;
		
		while (cin >> value) {
			if (head == NULL) {
				head = new ListNode(value);    //��ע������һ��ʼheadΪNULL������ֱ����head->val = value������ᱨ��ָ���쳣
				p = head;     //pӦ�������︳ֵ������p��һֱΪ�գ�
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

	//�������β�巨
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

	//�������ɾ����ɾ��ָ��ֵ�����нڵ㣻����ɾ���������
	ListNode* list_remove(int x) {
		//��Ϊ����ͷ��㣬���Բ���ɾ�������������һ����㣬��Ϊ���������ͷ��
		ListNode* first = new ListNode(-1);
		first->next = head;

		ListNode* p = first;

		while (p->next != NULL) {  //ѭ���������ڶ����ڵ�
			if (p->next->val == x) {
				ListNode* q = p->next;   //����Ҫɾ���Ľ��
				p->next = p->next->next;  //��Ҫɾ���ĺ�һ���ڵ����ӵ�ǰһ���ڵ��next��
				delete q;   //�ͷ��ڴ�
			}
			p = p->next;  //����
		}

		return head;
	}

	//������ı������
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
	//����������
	int value;
	SingleList list;    //�����ｨ������SingleList�ṹ��Ķ��󣬶���new���ص���ָ��ýṹ���ָ��
	//������ýṹ���еķ�����.���ɣ���ָ�������Ҫ->
	cout << "�����������е�ֵ��" << endl;
	/*
	while (cin >> value) {
		list.list_insert(value);

		if (cin.get() == '\n') {
			break;
		}
	}
	*/

	list.list_create();

	//���������
	cout << "ԭ������Ϊ��" << endl;
	list.list_traverse();

	//ɾ��ֵΪx�Ľڵ�
	list.list_remove(3);

	//���ɾ����ĵ�����
	cout << "ɾ����ĵ�����Ϊ��" << endl;
	list.list_traverse();
}