/**
* ͬһ�������ʵ�ֿ��������㷨���۷�����
* ����˼�루���ݹ飩
*/

#include <iostream>

using namespace std;

//ѡ���׼�����������飬����ԭַ����
int partitionSeq(int A[], int p, int r)
{
    //p��r�ֱ��ʾ����Ŀ�ͷ�ͽ�β
    int x, i;
    x = A[r]; //�������е����һ��ֵΪ��׼����x����
    i = p - 1; //i���ڱ���Ȼ�׼��С��ֵ���ڵ�λ�ã���ʼΪ���鿪ͷǰһ��λ��

    int temp;
    for(int j=p; j<r; j++)
    {
        if(A[j] <= x)
        {
            i = i + 1;

            //������ǰλ�ú�ָʾ��С���±�λ�õ�ֵ
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    i = i + 1;   //��ʱλ���ϵ�ֵ�ǱȻ�׼�����ֵ�����±ߵĽ����л������
	
    temp = A[i];
    A[i] = A[r];
    A[r] = temp;

    return i;
}

//�ݹ���п�������
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
    cout << "����������ĸ�����" << endl;
    cin >> n;

    int A[n];

    cout << "�����������е�Ԫ�أ�" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    QuickSort(A,0,n-1);
    //������
    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
