#include <iostream>

using namespace std;

//定义链表节点结构体
struct ListNode{
    int val; //数据域
    ListNode *next; //指针域

    //构造函数
    ListNode(int data): val(data), next(NULL) {}
};

//创建单链表
ListNode* cteateList(ListNode *head)
{
    ListNode *p = head;

    cout << "请输入单链表的元素值："  << endl;

    int value;
    while(cin >> value){
        ListNode *newnode = new ListNode(value);
        p->next = newnode;
        p = p->next;

        if(cin.get() == '\n')
            break;
    }

    return head->next;
}

//找到中间节点
ListNode* middleNode(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;

    ListNode* slow=head;  //慢指针一次走一步
    ListNode* fast=head;  //快指针一次走两步

    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->next;  // 指向中间节点
}

int main()
{
     cout << "建立单链表" << endl;

    ListNode *head = new ListNode(0);
    ListNode *mlist = cteateList(head);

    ListNode *middle = middleNode(mlist);
    cout << "中间节点中的元素值为：" << middle->val << endl;
    cout << "中间节点及后续值为：" ;
    ListNode *p = middle;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
