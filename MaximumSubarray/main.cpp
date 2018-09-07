/**
* 算法导论第一部分第4章：分治策略
* 实现查找最大子数组
*/
#include <iostream>

using namespace std;

//求跨中间分界线的最大子列和
int findMaxCrossingSum(int a[],int low,int mid,int high){
    int midMaxSum = 0;
    int leftSum = 0, leftMaxSum = 0;
    int rightSum = 0, rightMaxSum = 0;

    //从中间向左扫描
    for(int i=mid;i>=low;i--){
        leftSum += a[i];
        if(leftSum > leftMaxSum){
            leftMaxSum = leftSum;
        }
    }
    //从中间向右扫描
    for(int j=mid+1;j<=high;j++){
        rightSum += a[j];
        if(rightSum > rightMaxSum){
            rightMaxSum = rightSum;
        }
    }

    midMaxSum = leftMaxSum + rightMaxSum;
    return midMaxSum;
}

//递归求解最大子列和
int findMaximumSubarray(int a[],int low, int high){
    /*分*/
    if(low == high)
        //cout << "最大子数组中仅一个数：" << a[low];
        //cout << "最大子数组的和为：" << a[low];
        return a[low];

    int mid, leftMaxSum, rightMaxSum;
    mid = (low + high) / 2;

    leftMaxSum = findMaximumSubarray(a,low,mid); //计算左边子数组的最大和
    rightMaxSum = findMaximumSubarray(a,mid+1,high); //计算右边子数组的最大和

    int midMaxSum = 0;
    //计算跨越中点的子数组的最大和
    midMaxSum = findMaxCrossingSum(a,low,mid,high);

    /*治*/
    int maxSum = 0;
    if(leftMaxSum >= rightMaxSum && leftMaxSum >= midMaxSum){
        maxSum = leftMaxSum;
    }
    else if(rightMaxSum > leftMaxSum && rightMaxSum > midMaxSum){
        maxSum = rightMaxSum;
    }
    else
        maxSum = midMaxSum;

    return maxSum;
}

int main()
{
    int n;
    cout << "请输入所求数组的个数：" << endl;
    cin >> n;

    int a[n];
    cout << "请输入所求数组：" << endl;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int maxSum = 0;
    maxSum = findMaximumSubarray(a,0,n-1);
    cout << "最大子数组的和为：" << maxSum << endl;
    return 0;
}
