/*
**��C++�򵥵�ʵ��һ�·�ת������Ĳ���
*/
#include <iostream>

using namespace std;

//�������ṹ�壬����ӹ��캯��
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

//��������������ֵ
void display(ListNode *first){
    if(first == NULL){
        cout << "��������û��ֵ" << endl;
        return;
    }
    else{
        ListNode *p = first;
        while(p){
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
}

//���е�����ķ�ת
ListNode* reverseLinkedList(ListNode *first){
    ListNode *prev = first;
    ListNode *cur = first->next;
    ListNode *next = NULL;
    while(cur){
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }
    first->next = NULL;
    first = prev;

    return first;
}

int main()
{
    int n, value;
    ListNode *first, *last;
    first = last = NULL;

    cout << "�������������" << endl;
    cin >> n;

    cout << "���������֣�" << endl;
    //����������
    for(int i=0;i<n;i++){
        cin >> value;
        if(first == NULL){
            first = new ListNode(value);
            last = first;
        }
        else{
            last->next = new ListNode(value);
            last = last->next;
        }
    }

    display(first);

    //����ת���������first
    first = reverseLinkedList(first);
    display(first);

    return 0;
}
