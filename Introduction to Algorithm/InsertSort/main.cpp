/**
ʵ�ּ򵥵�ֱ�Ӳ�������
ʹ����������С��������
*/

#include <iostream>

using namespace std;

void InsertSort(int a[],int length){
    //����
    int key;
    int i, j;
    for(j=1;j<length;j++){
        key = a[j]; //key����������ֵ
        i = j-1;
        while(a[i] > key && i >= 0){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
    //���
    for(int i=0;i<length;i++){
        cout << a[i]  << " ";
    }
    cout << endl;
}

int main()
{
    int length;
    cout << "����������ĳ��ȣ�"  << endl;
    cin >> length;

    int a[length];
    //int num;
    cout << "���������������У�" << endl;

    for(int i=0;i<length;i++){
        cin >> a[i];
    }

    InsertSort(a,length);
    return 0;
}
