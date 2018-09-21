/**
* 计数排序的简单实现
* 线性时间排序，通过计算进行排序，而非比较；
* 计数排序是稳定的；
*/
#include <iostream>

using namespace std;

void CountingSort(int A[], int B[], int n, int k)
{
    int C[k]; // 数组C提供临时存储空间，保存数组A中值为i的元素的个数————所有比i小的元素的个数
    for(int i=0;i<=k;i++){
        C[i] = 0; // 对数组C进行初始化
    }

    for(int j=0;j<n;j++){
        C[A[j]] = C[A[j]] + 1; // 数组C中的下标等同数组A中的元素，对应下标中存储该元素的个数
    }

    for(int i=1;i<=k;i++){
        C[i] = C[i] + C[i-1]; // 数组C的下标存储比下标值小以及等同于下标值的元素个数
    }

    for(int j=n-1;j>=0;j--){
        B[C[A[j]]-1] = A[j]; // 根据对应下标值的数组C中的个数，找到元素A[j]的最终位置
        C[A[j]] = C[A[j]] - 1; // 因为可能存在相同元素，所以需要放入一个值后将个数减一，使得下一个值为A[j]的元素会放到
                               // 数组B中已经存放相同元素的前一个位置上
    }
}

int main()
{
    int n, k;
    cout << "请输入数组的个数：" << endl;
    cin >> n;
    cout << "请输入数的最大边界（最小边界为0）：" << endl;
    cin >> k;

    int A[n];
    cout << "请输入数组中的元素：" << endl;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    int B[n]; // 数组B用于保存最终排好序的数组
    for(int i=0;i<n;i++){
        B[i] = 0; // 对数组B进行初始化
    }

    CountingSort(A,B,n,k);
    cout << "进行计数排序后的元素序列为：" << endl;
    for(int i=0;i<n;i++){
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}
