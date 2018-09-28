#include <iostream>
#include "HashTable.h"

using namespace std;

/**
* ɢ�б��һ�ּ�ʵ��
* �ó�������������ɢ�к������������������ͻ
* ע��ʹ��C++�е���ģ�壬��ֵ�Կ���ѡ����������
*/

int main()
{
    HashTable<int,int> ht(13);
    int a[] = {34,78,25,69,12,46,9,22};
    for(int i=0;i<8;i++)
        ht.hash_Insert(a[i],i); // ���Լ�ֵ�ԵĲ���[����ɢ�б�]
    cout << "current size=" << ht.hash_Size() << endl;
    cout << "key=69,value=" << ht.hash_Search(69) << endl; // ����Ԫ��ֵ�Ĳ�ѯ
    ht.hash_Delete(9); // ���Լ�ֵ�Ե�ɾ��
    cout << "after delete��size=" << ht.hash_Size() << endl;
    return 0;
}
