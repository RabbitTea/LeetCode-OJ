/**
* �㷨���۵�һ���ֵ�4�£����β���
* ʵ�ֲ������������
*/
#include <iostream>

using namespace std;

//����м�ֽ��ߵ�������к�
int findMaxCrossingSum(int a[],int low,int mid,int high){
    int midMaxSum = 0;
    int leftSum = 0, leftMaxSum = 0;
    int rightSum = 0, rightMaxSum = 0;

    //���м�����ɨ��
    for(int i=mid;i>=low;i--){
        leftSum += a[i];
        if(leftSum > leftMaxSum){
            leftMaxSum = leftSum;
        }
    }
    //���м�����ɨ��
    for(int j=mid+1;j<=high;j++){
        rightSum += a[j];
        if(rightSum > rightMaxSum){
            rightMaxSum = rightSum;
        }
    }

    midMaxSum = leftMaxSum + rightMaxSum;
    return midMaxSum;
}

//�ݹ����������к�
int findMaximumSubarray(int a[],int low, int high){
    /*��*/
    if(low == high)
        //cout << "����������н�һ������" << a[low];
        //cout << "���������ĺ�Ϊ��" << a[low];
        return a[low];

    int mid, leftMaxSum, rightMaxSum;
    mid = (low + high) / 2;

    leftMaxSum = findMaximumSubarray(a,low,mid); //������������������
    rightMaxSum = findMaximumSubarray(a,mid+1,high); //�����ұ������������

    int midMaxSum = 0;
    //�����Խ�е�������������
    midMaxSum = findMaxCrossingSum(a,low,mid,high);

    /*��*/
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
    cout << "��������������ĸ�����" << endl;
    cin >> n;

    int a[n];
    cout << "�������������飺" << endl;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int maxSum = 0;
    maxSum = findMaximumSubarray(a,0,n-1);
    cout << "���������ĺ�Ϊ��" << maxSum << endl;
    return 0;
}
