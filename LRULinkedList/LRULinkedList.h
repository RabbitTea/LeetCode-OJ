#ifndef LRULINKEDLIST_H_INCLUDED
#define LRULINKEDLIST_H_INCLUDED

/**
* @description: ���ԡ���C++�����ݽṹ����˫������ʵ���㷨����LRU������̭�㷨
* @idea: ��������ľ�̬��С�����û���Ҫ����ĳ������ʱ����ͷ����˫������������ҵ������ݣ��򽫶�Ӧ�Ľ���ԭλ��
         ɾ�����ٲ��뵽����ͷ�������û���ҵ������ݣ�����Ҫ�ж��������������������
                                �� ����δ�������½���㱣�������ֱ�Ӳ��뵽����ͷ����
                                �� ������������ɾ����β��㡾������δʹ�õĽ�㡿�����½���㱣������ݲ��뵽����ͷ����
* @author: Sandra
* @date: 2018/10/3
**/

#include <iostream>

using namespace std;

//����������ṹ��
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

//����˫������ṹ��
struct LRULinkedList{
public:
    LRUNode *head;
    const int len = 5; // �涨����Ľ�����

public:
    LRULinkedList();// ���캯��
    ~LRULinkedList(); // ��������

    int isOutofRange(LRULinkedList *mlist); // �ж������еĽ������Ƿ񳬹��涨������len����������true��û��������false

    LRUNode* searchNode(LRULinkedList *mlist, int value); // ���ʸ��������ݣ�����ָ���Ӧ����ָ�룬�������ڷ���NULL
    int isExist(LRULinkedList *mlist, int value); // ���ʸ��������ݣ�������������з���true�����򷵻�false

    void insertData(LRULinkedList *mlist, int value); // ���ݸ���������ֵ�����㵽�������Ӧλ��
    void deleteData(LRULinkedList *mlist); // ��������ɾ�������������ڵĽ��

    void printData(LRULinkedList *mlist); // ��ͷ����˫���������Ԫ��ֵ
};

// �����캯��
LRULinkedList::LRULinkedList()
{
    head = NULL;
    //const int len = 5;
}

// ������������
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

// �ж������еĽ������Ƿ񳬹��涨������len����������true��û��������false
int LRULinkedList::isOutofRange(LRULinkedList *mlist)
{
    int lcount = 0;
    LRUNode *p = mlist->head;
    while(p != NULL){
        lcount++;
        p = p->next;
    }
    if(lcount < mlist->len) // �涨���Ҳ���ǳ���
        return 0;
    else
        return 1;
}

// ���ʸ��������ݣ�����ָ���Ӧ����ָ�룬�������ڷ���NULL
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

// ���ʸ��������ݣ�������������з���true�����򷵻�false
int LRULinkedList::isExist(LRULinkedList *mlist, int value)
{
    LRUNode *p = mlist->head;
    while(p != NULL){
        if(p->data == value)
            return 1; // �ҵ�����true
        p = p->next;
    }
    return 0; // û�ҵ�����false
}

// ���ݸ���������ֵ�����㵽�������Ӧλ��
/**LRU�����㷨������Ĳ���������в��뵽����ͷ����һ�����**/
void LRULinkedList::insertData(LRULinkedList *mlist, int value)
{
    LRUNode *p = new LRUNode(value); // ����Ԫ��ֵ�½�һ�����

    if(mlist->head == NULL){ // Ҫ�ж������Ƿ�Ϊ�յ����
        head = p;
    }
    else{
        p->next = mlist->head;
        mlist->head->prev = p;
    }
    head = p; // ÿ��ͷ��֮����²���Ľ��Ϊ�����ͷ���
}

// ��������ɾ�������������ڵĽ��
/**LRU�����㷨�������ɾ����������ɾ����β�����һ�����**/
void LRULinkedList::deleteData(LRULinkedList *mlist)
{
    // �ȱ�������β���
    LRUNode *p = mlist->head;
    while(p->next != NULL){
        p = p->next;
    }

    // ����β���ɾ��
    p->prev->next = NULL;
    p->prev = NULL;
    delete p;
}

// ��ͷ����˫���������Ԫ��ֵ
void LRULinkedList::printData(LRULinkedList *mlist)
{
    LRUNode *p = mlist->head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
#endif // LRULINKEDLIST_H_INCLUDED
