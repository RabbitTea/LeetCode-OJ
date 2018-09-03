/**
  实现简单的二路归并排序
*/
#include <iostream>

using namespace std;

//子步骤——合并，在每层递归中调用
void Merge(int a[],int first,int mid,int last){
    int n1, n2;
    //得到两个子序列的长度
    n1 = mid - first + 1;
    n2 = last - mid;

    int L[n1+1], R[n2+1];
    //分别读取到两个数组中
    for(int i=0;i<n1;i++){
        L[i] = a[first+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = a[mid+1+i];
    }
    L[n1+1] = 9999; //取较大数表示数组的结尾
    R[n2+1] = 9999;

    //依次从头比较两个数组中的元素，选最小者到原来的数组中
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
    //如果其中一个数组到达结尾，便把另一个数组剩下的元素依次加入输出的数组中
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

//归并排序(递归操作)
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
    cout << "请输入待排序的数字个数:" << endl;
    cin >> length;

    int a[length];
    cout << "请输入待排序的数字:" << endl;
    for(int i=0;i<length;i++){
        cin >> a[i];
    }

    MergeSort(a,0,length-1);
    cout << "按从小到大排序后为:" << endl;
    for(int i=0;i<length;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
