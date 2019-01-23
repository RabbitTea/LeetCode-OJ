/**
* @description: 判断用单链表存储的字符串是否为回文串
* @author: RabbitTea
* @date: 2018/10/4
**/
#include <iostream>
#include <cstring>
#include "PalindromeList.h"

using namespace std;

int main()
{
    char str1[6] = {'l','e','v','e','l'};
    SPList *slist = new SPList();

    for(int i=0;i<5;i++){
        slist->tailInsert(slist,str1[i]);
    }

    cout << "判断字符串'level'是否为回文串" << endl;
    SPNode *mid = slist->findMidNode(slist); // 找到指向链表中间结点的指针
    int halflen = slist->lenOfHalfList(slist); // 计算链表一半的长度
    if(slist->isPalindrome(slist,mid,halflen))
        cout << "level是回文串" << endl;
    else
        cout << "level不是回文串" << endl;

    return 0;
}
