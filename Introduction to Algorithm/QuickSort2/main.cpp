/**
* 快速排序的简单实现
* 首先把基准值取出来（留空），原址重排为正反方向交叉遍历（填空）
*/

#include <iostream>

using namespace std;

int partitionSeq(int A[], int low, int high){
    int pivot = A[low]; //选取数组第一个元素为基准值，用pivot保存

    while(low < high){
        //基准值在开头，所以先从后往前遍历
        while(low < high && A[high] >= pivot)
            --high;
        A[low] = A[high]; //遇到比基准值小的数将其填到前面的空处
        while(low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low]; //遇到比基准值大的数将其填到后面的空处
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
    cout << "请输入数组的个数：" << endl;
    cin >> n;

    int A[n];
    cout << "请输入数组中的元素：" << endl;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    QuickSort(A,0,n-1);
    //输出
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
