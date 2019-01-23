#include <iostream>
#include "LRULinkedList.h"
/**
* ���Ի���˫�������LRU�����㷨
**/
using namespace std;

int main()
{
    int arr[5] = {6,3,8,2,9};
    LRULinkedList *mlist = new LRULinkedList(); // ����һ��˫������

    cout << "*****���ݸ������齨��˫������*****" << endl;
    cout << "���Ԫ�أ�";
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
        mlist->insertData(mlist,arr[i]);
    }
    cout << endl;

    int value;
    cout << "*****����ָ��������*****" << endl;
    cout << "������Ҫ���ʵ����ݣ�" << endl;
    cin >> value;

    if(mlist->isExist(mlist,value)){ // ��������������
        cout << value << "���ҵ�" << endl;
    }
    else  // ���ݲ���������
    {
        cout << value << "δ�ҵ����������������" << endl;
        if(mlist->isOutofRange(mlist)) {// ��������еĽ�����������������������
            mlist->deleteData(mlist);
            mlist->insertData(mlist,value);
        }
        else
            mlist->insertData(mlist,value);
    }

    cout << "*****˳�����˫������*****" << endl;
    mlist->printData(mlist);
    cout << endl;
    return 0;
}
