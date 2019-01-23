/**
实现简单的直接插入排序
使整数序列由小到大排列
*/

#include <iostream>

using namespace std;

void InsertSort(int a[],int length){
    //排序
    int key;
    int i, j;
    for(j=1;j<length;j++){
        key = a[j]; //key保存待排序的值
        i = j-1;
        while(a[i] > key && i >= 0){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
    //输出
    for(int i=0;i<length;i++){
        cout << a[i]  << " ";
    }
    cout << endl;
}

int main()
{
    int length;
    cout << "请输入数组的长度："  << endl;
    cin >> length;

    int a[length];
    //int num;
    cout << "请输入待排序的数列：" << endl;

    for(int i=0;i<length;i++){
        cin >> a[i];
    }

    InsertSort(a,length);
    return 0;
}
