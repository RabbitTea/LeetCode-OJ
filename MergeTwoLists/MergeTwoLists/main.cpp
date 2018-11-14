#include <iostream>
#include <stdlib.h>

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

//进行两个链表的合并
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    //其一为空
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    /*
    ListNode* newHead = ListNode(0);   // 建立合并后链表的头节点
    ListNode* p = newHead;
    */

   if(l1->val <= l2->val){
       ListNode *newlist = l1;
       newlist->next = mergeTwoLists(l1->next, l2);  // 在判断的过程中建立新链表
       return newlist;
   }else{
       ListNode *newlist = l2;
       newlist->next = mergeTwoLists(l1, l2->next);
       return newlist;
   }
}

int main()
{
    cout << "建立第一个单链表" << endl;
    ListNode *head1 = new ListNode(0);
    ListNode *l1 = cteateList(head1);

    cout << "建立第二个单链表" << endl;
    ListNode *head2 = new ListNode(0);
    ListNode *l2 = cteateList(head2);

    ListNode *newlist = mergeTwoLists(l1, l2);

    cout << "合并后的单链表为：" << endl;
    ListNode *p = newlist;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
