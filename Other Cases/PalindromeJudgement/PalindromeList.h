#ifndef PALINDROMELIST_H_INCLUDED
#define PALINDROMELIST_H_INCLUDED
/**
* ���ݽṹ��������������
* �洢���󡪡������ַ���
* ��⡪�������жϸ������ַ����Ƿ�Ϊ���Ĵ�[�����ͷ�������ͬ]
* �㷨���������������������
*         1. �ҵ�������м��㣬����һ��ָ��mid���桪�����������������
             ָ��p��qͬʱָ������ͷ����ͬʱ���Ʊ�����ֻ����pÿ�β���Ϊ1��qÿ�β���Ϊ2��
             ��q�ƶ�������β��ʱ��p�պ��ƶ���������м���λ�á�
*         2. �ҵ�������������Ӧ�ַ����ڵĽ�㣬�Ƚ����е��ַ��Ƿ���ȣ������������Ƚϣ�
             ���������ֱ���˳������ء����ǻ��Ĵ����Ľ����
             ָ��l������ͷ����ʼ��ָ��r�������м俪ʼ��ͬʱ��������lÿ�β���Ϊi(1,2,...,halflen)[�൱��1]��
             ��rÿ�β���Ϊ(halflen-i)[halflen-����]���Ƚ�����ָ��ָ��Ľ���е��ַ��Ƿ���ȡ�
**/

#include <iostream>

using namespace std;

//�����ַ�����������ṹ��
struct SPNode{
    char c;
    SPNode *next;

    SPNode(char ch){
        c = ch;
        next = NULL;
    }
};

//�����ַ���������ṹ��
struct SPList{
public:
    SPNode *head;

public:
    SPList();
    ~SPList();

    void tailInsert(SPList *slist, char ch); // β�巨�����ַ���������

    SPNode* findMidNode(SPList *slist); // �ҵ���������м��㣬����ָ���м����ָ��
    int lenOfHalfList(SPList *slist); // ���㵥����һ��ĳ���

    int isPalindrome(SPList *slist, SPNode *mid,int halflen); // �жϵ������д洢���ַ����Ƿ�Ϊ���Ĵ�
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

// β�巨�����ַ���������
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

// ���㵥����һ��ĳ���
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

// �ҵ���������м��㣬����ָ���м����ָ��
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

// �жϵ������д洢���ַ����Ƿ�Ϊ���Ĵ�
int SPList::isPalindrome(SPList *slist, SPNode *mid, int halflen)
{
    SPNode *l = slist->head;
    SPNode *r = mid;

    for(int i=1;i<=halflen;i++){
        if(l==mid || r==mid)
            return 1; // ����1��ʾ�ַ����ǻ��Ĵ�
        l = l->next;
        for(int j=1;j<=halflen-i;j++){
            r = r->next;
        }

        // �Ƚ�
        if(l->c == r->c)
            continue;
        else
            return 0; // ����0��ʾ�ַ������ǻ��Ĵ�
    }
    return 1; // ����1��ʾ�ַ����ǻ��Ĵ�
}

#endif // PALINDROMELIST_H_INCLUDED
