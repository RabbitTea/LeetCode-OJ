/**

* 堆排序的简单实现
*/
#include <iostream>

using namespace std;

/**
* 在堆排序算法中，涉及三大基本操作：
*     ①维护最大堆的性质（MAX-HEAPIFY）：保证各个子树根结点的值始终大于其左右子结点；
      ②建立大根堆（BUILD-MAX-HEAP）：其关键点为要知道【最后一个结点是第[n/2]个结点的孩子】，
                                      所以从第[n/2]个结点开始依次往前进行最大堆性质的维护；
      ③进行堆排序（HEAP-SORT）：实质是对大根堆的删除操作，依次删除完全二叉树的根结点：该操作通过交换
                                  结点与最后一个结点的元素值，每次通过缩小堆大小来删除最后一个结点。
                                【需要明确A.length表示的下标指向最后一个结点，因为根是从1开始的】，所以循环的下标从长度值开始递减；
                                  每次删除操作后要对大根堆的性质进行维护（因为将堆底元素交换到堆顶可能会破坏性质）；
* 基本知识：逻辑上将待排序整体看做一颗【完全二叉树】的顺序存储结构；
             实质上待排序元素为一个数组，因为完全二叉树的性质，其父结点、左孩子结点、右孩子结点的下标很容易通过数学方法找到；
* 最大堆进行堆排序实现升序输出的原理：最大堆只是逻辑上表现为一颗二叉树，其实质传序列值和保存还是用的数组，所以在建好最大堆后，
                                        每次把根结点的值替换到最后，实质上是移动到了数组的末尾（仍保留在数组中）；然后进行最大堆
                                        性质的调整，把调整范围缩小到已经替换下来的最大值之前；直至终止时数组中的元素就按由小到大
                                        排好序了，这时直接输出就可以。
*/

// 维护最大堆的性质
void Max_Heapify(int A[], int n, int i)
{
    int left = 2 * i + 1; //left保存i的左孩子的下标
    int right = 2 * i + 2; //right保存i的右孩子的下标
    int largest; // largest保存当前最大值所在的下标

    //通过将i中的值和其左右孩子中的值比较，得到最大值的下标
    if(left <= n && A[left] > A[i])
        largest = left;
    else
        largest = i;
    if(right <= n && A[right] > A[largest])
        largest = right;

    //如果i指向的元素不是最大值，则将其与最大值交换
    if(i != largest){
        int temp = 0;
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        Max_Heapify(A,n,largest); //递归调用Max_Heapify继续向下调整
    }
}

// 建立最大堆
void Build_Max_Heap(int A[], int n)
{
    //从最后一个结点的父结点开始，依次向前维护最大堆的性质（向上调整）
    for(int i=(n+1)/2-1;i>=0;i--){
        Max_Heapify(A,n,i);      //向前处理每一个节点时，都向下调整一直到不能调整的位置
    }
}

// 进行堆排序
void HeapSort(int A[], int n)
{
    //构造最大堆
    Build_Max_Heap(A,n);

    //依次摘除根结点：将根结点与最后一个结点的元素值交换，通过每次缩小数组的一个长度来实现删除
    for(int i=n;i>=0;i--){  //每摘除一个节点，总长度会变小，即最后一个节点的索引位置会变小；△但原来索引处交换后的元素仍存在
        //cout << A[1] << " ";

        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;

        Max_Heapify(A,i-1,0); //每次交换和删除后自上而下进行最大堆性质的调整
    }
}

int main()
{
    int length;
    cout << "请输入待排序元素的个数：" << endl;
    cin >> length;
    
    int A[length];
    cout << "请依次输入待排序元素：" << endl;
    for(int i=0;i<length;i++){
        cin >> A[i];
    }

    HeapSort(A,length-1);

    cout << "进行堆排序后的数据顺序为：" << endl;
    for(int i=0;i<length;i++){
        cout << A[i];
    }
    cout << endl;

    return 0;
}
