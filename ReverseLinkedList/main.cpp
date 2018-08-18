/*
**用C++简单的实现一下反转单链表的操作
*/
#include <iostream>

using namespace std;

//创建结点结构体，并添加构造函数
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

//输出整个单链表的值
void display(ListNode *first){
    if(first == NULL){
        cout << "单链表中没有值" << endl;
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

//进行单链表的反转
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

    cout << "请输入结点个数：" << endl;
    cin >> n;

    cout << "请输入数字：" << endl;
    //创建新链表
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

    //将反转后的链表赋给first
    first = reverseLinkedList(first);
    display(first);

    return 0;
}
