/**
* @description: Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
                [����������Χ������Ϊ[1,n]���Ҹ���������Ԫ�صĸ���k�����[1,n]֮�����к�k��Ԫ�ص�������]
* @idea: ѡ����򵥵ķ�������Ƕ��ѭ�������α�������ע�������ʽ
* @author: SA18225018
* @date: 2018/10/17
**/
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cout << "���������������ֵn��" << endl;
    cin >> n;

    cout << "������������ķ�Χk��" << endl;
    cin >> k;

    for(int i=1;i<=n;i++){ // i����ȷ����һ��Ԫ��ֵ
        int p = i;  // p��������iֵ����Ϊ����һ��ѭ��ʱ��Ҫ��p���ƣ�
        for(int j=p+1;j<=n;j++,p++){ // j����ȷ���ڶ���Ԫ��ֵ
            cout << '[' << i << ',';
            for(int q=j;q<p+k-1;q++){ // p���������ߵ�2����k��ֵ
                cout << q << ',';
            }
            cout << p+k-1 << ']' << endl;
        }
    }
    return 0;
}
