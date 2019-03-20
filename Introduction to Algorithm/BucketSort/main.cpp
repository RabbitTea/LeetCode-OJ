/**
* Ͱ����ļ�ʵ��
* ˼�룺����һ�����е����ֵmax������[0-max]��Ͱ���飬���±�Ͷ�Ӧ������A�е�Ԫ��ֵ��
        ��Ͱ���齨���ò�ͳ�ƺü�¼�ĸ���֮��ʹ���A�е�Ԫ���Ѿ������ˣ���ʱֻҪ��ӦͰ�����д洢�ĸ�����
        ���η���ֵ[Ͱ������±�]������A�м��ɡ�
*/
#include <iostream>

void BucketSort(int A[], int n, int Max)
{
    //����Ͱ���飬����ʼ��
    int buckets[Max];
    for(int i=0;i<=Max;i++){
        buckets[i] = 0;
    }

    int i,j;
    //����
    for(j=0;j<n;j++){
        buckets[A[j]]++;
    }

    //��������iָʾͰ����buckets�е��±꣬jָʾԭ����A�е��±�
    for(i=0,j=0;i<=Max;i++){
        while(buckets[i]-- > 0)
            A[j++] = i;

        /* ��һ��д�� */
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
    cout << "����������ĸ�����" << endl;
    cin >> n;
    cout << "�������������ֵ��" << endl;
    cin >> Max;

    int A[n];
    cout << "�����������е�����" << endl;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    BucketSort(A,n,Max);
    cout << "������˳��Ϊ��" << endl;
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
