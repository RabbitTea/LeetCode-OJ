/**
* @description: �ж��õ�����洢���ַ����Ƿ�Ϊ���Ĵ�
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

    cout << "�ж��ַ���'level'�Ƿ�Ϊ���Ĵ�" << endl;
    SPNode *mid = slist->findMidNode(slist); // �ҵ�ָ�������м����ָ��
    int halflen = slist->lenOfHalfList(slist); // ��������һ��ĳ���
    if(slist->isPalindrome(slist,mid,halflen))
        cout << "level�ǻ��Ĵ�" << endl;
    else
        cout << "level���ǻ��Ĵ�" << endl;

    return 0;
}
