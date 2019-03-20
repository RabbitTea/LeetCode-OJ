/**
* 桶排序的简单实现
* 思想：给定一组数中的最大值max，建立[0-max]的桶数组，其下标就对应了数组A中的元素值；
        【桶数组建立好并统计好记录的个数之后就代表A中的元素已经有序了，这时只要对应桶数组中存储的个数，
        依次放数值[桶数组的下标]到数组A中即可】
*/
#include <iostream>

void BucketSort(int A[], int n, int Max)
{
    //创建桶数组，并初始化
    int buckets[Max];
    for(int i=0;i<=Max;i++){
        buckets[i] = 0;
    }

    int i,j;
    //计数
    for(j=0;j<n;j++){
        buckets[A[j]]++;
    }

    //排序；其中i指示桶数组buckets中的下标，j指示原数组A中的下标
    for(i=0,j=0;i<=Max;i++){
        while(buckets[i]-- > 0)
            A[j++] = i;

        /* 另一种写法 */
        /*
        while(buckets[i]-- > 0){
            A[j] = i;
            j++;
            i++;
        }
        */
    }
}

using namespace std;

int main()
{
    int n, Max;
    cout << "请输入数组的个数：" << endl;
    cin >> n;
    cout << "请输入数的最大值：" << endl;
    cin >> Max;

    int A[n];
    cout << "请输入数组中的数：" << endl;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    BucketSort(A,n,Max);
    cout << "排序后的顺序为：" << endl;
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
