#ifndef LRULINKEDLIST_H_INCLUDED
#define LRULINKEDLIST_H_INCLUDED

/**
* @description: 语言——C++；数据结构——双向链表；实现算法——LRU缓存淘汰算法
* @idea: 给定链表的静态大小；当用户需要访问某个数据时，从头遍历双向链表；如果查找到该数据，则将对应的结点从原位置
         删除，再插入到链表头部；如果没查找到该数据，则需要判断两种情况——————
                                ① 链表未满，则新建结点保存该数据直接插入到链表头部；
                                ② 链表已满，则删除链尾结点【最近最久未使用的结点】，再新建结点保存该数据插入到链表头部；
* @author: Sandra
* @date: 2018/10/3
**/

#include <iostream>

using namespace std;

//定义链表结点结构体
struct LRUNode{
public:
    int data;
    LRUNode *next;
    LRUNode *prev;

    LRUNode(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }

    LRUNode(int d,LRUNode *n,LRUNode *p){
        data = d;
        next = n;
        prev = p;
    }
};

//定义双向链表结构体
struct LRULinkedList{
public:
    LRUNode *head;
    const int len = 5; // 规定链表的结点个数

public:
    LRULinkedList();// 构造函数
    ~LRULinkedList(); // 析构函数

    int isOutofRange(LRULinkedList *mlist); // 判断链表中的结点个数是否超过规定的容量len：超过返回true，没超过返回false

    LRUNode* searchNode(LRULinkedList *mlist, int value); // 访问给定的数据，返回指向对应结点的指针，若不存在返回NULL
    int isExist(LRULinkedList *mlist, int value); // 访问给定的数据，若其存在链表中返回true，否则返回false

    void insertData(LRULinkedList *mlist, int value); // 根据给定的数据值插入结点到链表的相应位置
    void deleteData(LRULinkedList *mlist); // 从链表中删除给定数据所在的结点

    void printData(LRULinkedList *mlist); // 从头遍历双向链表，输出元素值
};

// 链表构造函数
LRULinkedList::LRULinkedList()
{
    head = NULL;
    //const int len = 5;
}

// 链表析构函数
LRULinkedList::~LRULinkedList()
{
    LRUNode *x = head;
    while(head != NULL){
        x = head;
        head = head->next;
        delete x;
    }
    delete head;
}

// 判断链表中的结点个数是否超过规定的容量len：超过返回true，没超过返回false
int LRULinkedList::isOutofRange(LRULinkedList *mlist)
{
    int lcount = 0;
    LRUNode *p = mlist->head;
    while(p != NULL){
        lcount++;
        p = p->next;
    }
    if(lcount < mlist->len) // 规定相等也算是超过
        return 0;
    else
        return 1;
}

// 访问给定的数据，返回指向对应结点的指针，若不存在返回NULL
LRUNode* LRULinkedList::searchNode(LRULinkedList *mlist, int value)
{
    LRUNode *p = mlist->head;
    while(p != NULL){
        if(p->data == value)
            return p;
        p = p->next;
    }
    return p;
}

// 访问给定的数据，若其存在链表中返回true，否则返回false
int LRULinkedList::isExist(LRULinkedList *mlist, int value)
{
    LRUNode *p = mlist->head;
    while(p != NULL){
        if(p->data == value)
            return 1; // 找到返回true
        p = p->next;
    }
    return 0; // 没找到返回false
}

// 根据给定的数据值插入结点到链表的相应位置
/**LRU缓存算法中链表的插入操作仅有插入到链表头部这一种情况**/
void LRULinkedList::insertData(LRULinkedList *mlist, int value)
{
    LRUNode *p = new LRUNode(value); // 根据元素值新建一个结点

    if(mlist->head == NULL){ // 要判断链表是否为空的情况
        head = p;
    }
    else{
        p->next = mlist->head;
        mlist->head->prev = p;
    }
    head = p; // 每次头插之后更新插入的结点为链表的头结点
}

// 从链表中删除给定数据所在的结点
/**LRU缓存算法中链表的删除操作仅有删除链尾结点这一种情况**/
void LRULinkedList::deleteData(LRULinkedList *mlist)
{
    // 先遍历到链尾结点
    LRUNode *p = mlist->head;
    while(p->next != NULL){
        p = p->next;
    }

    // 将链尾结点删除
    p->prev->next = NULL;
    p->prev = NULL;
    delete p;
}

// 从头遍历双向链表，输出元素值
void LRULinkedList::printData(LRULinkedList *mlist)
{
    LRUNode *p = mlist->head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
#endif // LRULINKEDLIST_H_INCLUDED
