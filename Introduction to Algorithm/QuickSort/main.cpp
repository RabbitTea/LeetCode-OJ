/**
* 同一方向遍历实现快速排序（算法导论方法）
* 分治思想（含递归）
*/

#include <iostream>

using namespace std;

//选择基准，并划分数组，进行原址重排
int partitionSeq(int A[], int p, int r)
{
    //p和r分别表示数组的开头和结尾
    int x, i;
    x = A[r]; //以数组中的最后一个值为基准，用x保存
    i = p - 1; //i用于保存比基准数小的值所在的位置，初始为数组开头前一个位置

    int temp;
    for(int j=p; j<r; j++)
    {
        if(A[j] <= x)
        {
            i = i + 1;

            //交换当前位置和指示较小数下标位置的值
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    i = i + 1;   //此时位置上的值是比基准数大的值，在下边的交换中换到最后
	
    temp = A[i];
    A[i] = A[r];
    A[r] = temp;

    return i;
}

//递归进行快速排序
void QuickSort(int A[], int p, int r)
{
    if(p < r)
    {
        int q;
        q = partitionSeq(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

int main()
{

    int n;
    cout << "请输入数组的个数：" << endl;
    cin >> n;

    int A[n];

    cout << "请输入数组中的元素：" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    QuickSort(A,0,n-1);
    //输出结果
    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
