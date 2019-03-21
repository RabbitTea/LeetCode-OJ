/*
* @Description�����������ã��ؼ���Ϊ�˲���������Ҫʹ�������ڵ�ָ�룬�ֱ�ָ��
                ��ǰ�ڵ㣬ǰһ���ڵ�ͺ�һ���ڵ㣻�ڶϵ���ǰ�ڵ��nextת��Ϊ
				����ǰһ���ڵ�ʱ����Ҫ����ԭ����next�ڵ㡣
*/

#include <iostream>

using namespace std;

//���嵥����ڵ�ṹ��
struct ListNode {
	int val;
	ListNode* next;

public:
	//���캯��
	ListNode(int value) {
		val = value;
		next = NULL;
	}

	//���뵥���������������
	ListNode* insertList() {
		
		int value;
		
		cout << "�����������е�ֵ��" << endl;
		//ͷ�ڵ㸳ֵ
		cin >> value;
		ListNode* head = new ListNode(value);

		//����ڵ�
		ListNode* p = head;
		while (cin >> value) {
			ListNode* newNode = new ListNode(value);  //�����½ڵ�
			p->next = newNode;  //����

			p = p->next;  //����

			if (cin.get() == '\n') {  //��ȡ�����з�ֱ���˳�
				break;
			}
		}

		return head;
	}

	//����������е�ֵ
	void traversePrint(ListNode* head) {
		ListNode* p = head;

		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
};


//�����������㷨
ListNode* reverseLinkedList(ListNode* head) {
	ListNode* prev = head;
	ListNode* cur = head->next;  //�ӵڶ����ڵ㿪ʼ����
	ListNode* next = NULL;

	while (cur) {  //curΪ�գ���curָ������β�ڵ�ĺ�һ���ڵ�ʱ�˳�ѭ��
		next = cur->next;   //�ȱ��浱ǰ����ڵ��ԭʼnext�򣬼���֤������
		cur->next = prev;  //��ת��ǰ�ڵ�
		
		//����
		prev = cur;
		cur = next;
	}

	head->next = NULL;
	head = prev;    //��ԭ����β��Ϊͷ

	return head;
}


int main() {

	//���쵥����
	ListNode* head = NULL;
	head = head->insertList();
	//head->traversePrint(head);

	//��������
	head = reverseLinkedList(head);

	//���
	cout << "���ú�Ľ��Ϊ��" << endl;
	head->traversePrint(head);
}