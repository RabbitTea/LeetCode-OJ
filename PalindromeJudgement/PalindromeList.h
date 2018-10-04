#ifndef PALINDROMELIST_H_INCLUDED
#define PALINDROMELIST_H_INCLUDED
/**
* 数据结构————单链表
* 存储对象————字符串
* 求解————判断给定的字符串是否为回文串[正读和反读都相同]
* 算法————两大基本操作：
*         1. 找到链表的中间结点，并用一个指针mid保存————快进慢进法；
             指针p、q同时指向链表头部，同时后移遍历，只不过p每次步长为1，q每次步长为2，
             则当q移动到链表尾部时，p刚好移动到链表的中间结点位置。
*         2. 找到链表中两个对应字符所在的结点，比较其中的字符是否相等，若相等则继续比较，
             若不相等则直接退出，返回“不是回文串”的结果；
             指针l从链表头部开始，指针r从链表中间开始，同时向后遍历，l每次步长为i(1,2,...,halflen)[相当于1]，
             而r每次步长为(halflen-i)[halflen-次数]，比较两个指针指向的结点中的字符是否相等。
**/

#include <iostream>

using namespace std;

//定义字符串单链表结点结构体
struct SPNode{
    char c;
    SPNode *next;

    SPNode(char ch){
        c = ch;
        next = NULL;
    }
};

//定义字符串单链表结构体
struct SPList{
public:
    SPNode *head;

public:
    SPList();
    ~SPList();

    void tailInsert(SPList *slist, char ch); // 尾插法建立字符串单链表

    SPNode* findMidNode(SPList *slist); // 找到单链表的中间结点，返回指向中间结点的指针
    int lenOfHalfList(SPList *slist); // 计算单链表一半的长度

    int isPalindrome(SPList *slist, SPNode *mid,int halflen); // 判断单链表中存储的字符串是否为回文串
};

SPList::SPList()
{
    head = NULL;
}

SPList::~SPList()
{
    SPNode *x = head;
    while(head != NULL){
        x = head;
        head = head->next;
        x->next = NULL;
        delete x;
    }
    delete head;
}

// 尾插法建立字符串单链表
void SPList::tailInsert(SPList *slist,char ch)
{
    SPNode *z = new SPNode(ch);
    SPNode *x = slist->head;
    if(x == NULL)
        slist->head = z;
    else{
        while(x->next != NULL){
            x = x->next;
        }
        x->next = z;
    }
}

// 计算单链表一半的长度
int SPList::lenOfHalfList(SPList *slist)
{
    int halflen = 0;

    SPNode *p = slist->head;
    SPNode *q = slist->head;

    if(slist->head == NULL){
        cout << "List Error" << endl;
        //return;
    }

    while(q->next != NULL){
        p = p->next;
        q = q->next->next;
        halflen++;
    }
    return halflen;
}

// 找到单链表的中间结点，返回指向中间结点的指针
SPNode* SPList::findMidNode(SPList *slist)
{
    SPNode *p = slist->head;
    SPNode *q = slist->head;

    if(slist->head == NULL){
        cout << "List Error" << endl;
        //return;
    }

    while(q->next != NULL){
        p = p->next;
        q = q->next->next;
    }
    return p;
}

// 判断单链表中存储的字符串是否为回文串
int SPList::isPalindrome(SPList *slist, SPNode *mid, int halflen)
{
    SPNode *l = slist->head;
    SPNode *r = mid;

    for(int i=1;i<=halflen;i++){
        if(l==mid || r==mid)
            return 1; // 返回1表示字符串是回文串
        l = l->next;
        for(int j=1;j<=halflen-i;j++){
            r = r->next;
        }

        // 比较
        if(l->c == r->c)
            continue;
        else
            return 0; // 返回0表示字符串不是回文串
    }
    return 1; // 返回1表示字符串是回文串
}

#endif // PALINDROMELIST_H_INCLUDED
