/**
* ��������ļ�ʵ��
* ���Ȱѻ�׼ֵȡ���������գ���ԭַ����Ϊ�������򽻲��������գ�
*/

#include <iostream>

using namespace std;

int partitionSeq(int A[], int low, int high){
    int pivot = A[low]; //ѡȡ�����һ��Ԫ��Ϊ��׼ֵ����pivot����

    while(low < high){
        //��׼ֵ�ڿ�ͷ�������ȴӺ���ǰ����
        while(low < high && A[high] >= pivot)
            --high;
        A[low] = A[high]; //�����Ȼ�׼ֵС���������ǰ��Ŀմ�
        while(low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low]; //�����Ȼ�׼ֵ��������������Ŀմ�
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high){
    if(low < high){
        int q = partitionSeq(A,low,high);
        QuickSort(A,low,q-1);
        QuickSort(A,q+1,high);
    }
}

int main()
{
    int n;
    cout << "����������ĸ�����" << endl;
    cin >> n;

    int A[n];
    cout << "�����������е�Ԫ�أ�" << endl;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    QuickSort(A,0,n-1);
    //���
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
