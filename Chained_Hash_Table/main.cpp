#include <iostream>
#include "HashTable.h"

using namespace std;

/**
* 散列表的一种简单实现
* 用除留余数法定义散列函数，用拉链法解决冲突
* 注：使用C++中的类模板，键值对可以选择任意类型
*/

int main()
{
    HashTable<int,int> ht(13);
    int a[] = {34,78,25,69,12,46,9,22};
    for(int i=0;i<8;i++)
        ht.hash_Insert(a[i],i); // 测试键值对的插入[构建散列表]
    cout << "current size=" << ht.hash_Size() << endl;
    cout << "key=69,value=" << ht.hash_Search(69) << endl; // 测试元素值的查询
    ht.hash_Delete(9); // 测试键值对的删除
    cout << "after delete，size=" << ht.hash_Size() << endl;
    return 0;
}
