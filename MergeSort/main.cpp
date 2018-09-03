/**
  ʵ�ּ򵥵Ķ�·�鲢����
*/
#include <iostream>

using namespace std;

//�Ӳ��衪���ϲ�����ÿ��ݹ��е���
void Merge(int a[],int first,int mid,int last){
    int n1, n2;
    //�õ����������еĳ���
    n1 = mid - first + 1;
    n2 = last - mid;

    int L[n1+1], R[n2+1];
    //�ֱ��ȡ������������
    for(int i=0;i<n1;i++){
        L[i] = a[first+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = a[mid+1+i];
    }
    L[n1+1] = 9999; //ȡ�ϴ�����ʾ����Ľ�β
    R[n2+1] = 9999;

    //���δ�ͷ�Ƚ����������е�Ԫ�أ�ѡ��С�ߵ�ԭ����������
    int i=0;
    int j=0;
    int k;
    for(k=first;k<=last;k++){
        if(L[i]==9999 && R[i]==9999)
            break;
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
    }
    //�������һ�����鵽���β�������һ������ʣ�µ�Ԫ�����μ��������������
    while(i<n1){
        a[k] = L[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k] = L[j];
        k++;
        j++;
    }

}

//�鲢����(�ݹ����)
void MergeSort(int a[],int first,int last){
    int mid;
    if(first < last){
        mid = (first + last)/2;
        MergeSort(a,first,mid);
        MergeSort(a,mid+1,last);
        Merge(a,first,mid,last);
    }
}

int main()
{
    int length;
    cout << "���������������ָ���:" << endl;
    cin >> length;

    int a[length];
    cout << "����������������:" << endl;
    for(int i=0;i<length;i++){
        cin >> a[i];
    }

    MergeSort(a,0,length-1);
    cout << "����С���������Ϊ:" << endl;
    for(int i=0;i<length;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
