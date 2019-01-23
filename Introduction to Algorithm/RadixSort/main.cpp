/**
* 基于数组的基数排序
* 按最低有效位进行排序
* 思想：将所有的待比较数值，统一为同样的数位长度，在数位较短的数前面补0
         从最低位开始，每轮用计数排序的思想进行稳定排序
*/
#include <iostream>

/**
* 为了补全位数，使所有数的位数都相同，要先找到数组中数的最大的位数
*/
int MaxBit(int A[],int n)
{
    int d = 1;
    for(int i=0;i<n;i++){
        int c = 1;
        int p = A[i]; // 将数组中的数保存下来，避免改变原本数组中的数
        while(p/10){
            p = p/10;
            c++;
        }
        if(c > d){
            d = c;
        }
    }
    return d;
}

void RadixSort(int A[],int n)
{
    int B[n]; //数组B用来存放最终排好序的元素
    for(int i=0;i<n;i++){
        B[i] = 0; // 对数组B进行初始化
    }

    int d = MaxBit(A,n); // 得到数组中数的最大位数
    int r = 1; // 用于作为除数，每次递增10的倍数以获得每位的位数

    /**
    * 对于每一位，用计数排序+桶排序的思想进行升序排列
    * 计数排序的思想：因为整型数的每位数值在[0-9]区间，所以最大值k的值为9;
    * 桶排序的思想：将每位数所在的[0-9]区间，均匀地划分为10个子区间，每个区间是一个桶，代表一位数值，
                     而桶中的记录为对应数值的个数;
    */
    for(int i=0;i<d;i++){ //对每一位的数值都要进行计数排序
        int countn[10]; // 准备一个桶数组，并对桶数组进行初始化
        for(int i=0;i<10;i++){
            countn[i] = 0;
        }

        //统计桶中的记录数
        for(int j=0;j<n;j++){
            int p = A[j] / r;
            int q = p % 10;
            countn[q]++;
        }

        //计算每个数值所在的位置
        for(int i=1;i<=9;i++){
            countn[i] = countn[i] + countn[i-1];
        }

        //将该位的数放到最终位置上
        for(int j=0;j<n;j++){
            int p = A[j] / r;
            int q = p % 10;
            B[countn[q]-1] = A[j];
            countn[q]--;
        }

        //把排序好的数组B复制到A
        for(int i=0;i<n;i++){
            A[i] = B[i];
        }
        r = r * 10; // 对高位依次处理
    }
}


using namespace std;

int main()
{
    int n;
    cout << "请输入待排序数的个数" << endl;
    cin >> n;

    int A[n];
    cout << "请输入数组中的数" << endl;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    RadixSort(A,n);
    cout << "排序后数组中数的顺序为：" << endl;
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
