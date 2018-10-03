#include <iostream>
#include "LRULinkedList.h"
/**
* 测试基于双向链表的LRU缓存算法
**/
using namespace std;

int main()
{
    int arr[5] = {6,3,8,2,9};
    LRULinkedList *mlist = new LRULinkedList(); // 创建一个双向链表

    cout << "*****根据给定数组建立双向链表*****" << endl;
    cout << "添加元素：";
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
        mlist->insertData(mlist,arr[i]);
    }
    cout << endl;

    int value;
    cout << "*****访问指定的数据*****" << endl;
    cout << "请输入要访问的数据：" << endl;
    cin >> value;

    if(mlist->isExist(mlist,value)){ // 数据已在链表中
        cout << value << "已找到" << endl;
    }
    else  // 数据不在链表中
    {
        cout << value << "未找到，将其插入链表中" << endl;
        if(mlist->isOutofRange(mlist)) {// 如果链表中的结点个数超过或等于链表的容量
            mlist->deleteData(mlist);
            mlist->insertData(mlist,value);
        }
        else
            mlist->insertData(mlist,value);
    }

    cout << "*****顺序遍历双向链表*****" << endl;
    mlist->printData(mlist);
    cout << endl;
    return 0;
}
