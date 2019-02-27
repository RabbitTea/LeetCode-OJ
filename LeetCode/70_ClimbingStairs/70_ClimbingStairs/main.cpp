/*
* @description����¥�ݣ�����n��̨�ף�һ��ֻ����1����2��������м����ߵ��յ�ķ�ʽ��
* @idea�� һά��̬�滮��Ŀ����νһά����ָ����������Ľ�����õ����ݽṹ�����ͣ�����������쳲��������У�
          ��n��̨�׵ķ�ʽ���ɵ�n-1�����1�͵�n-2�����2���ã����Եõ���ѧ���ʽ��f(n)=f(n-1)+f(n-2)��
		  ��ô���ǣ���һ��n+1��С��һά������Ա���1-n��̨�׵Ľ����
* @author��RabbitTea
* @date��2019/2/27
*/

#include <iostream>
#include <vector>

using namespace std;

int climbWays(int n) {
	//int *ways = new int[n+1];  //DP˼�룬����������Ľ��
	//int ways[n + 1] = { 0 };
	vector<int> ways(n + 1);
	
	//1��̨����һ���߷���2��̨���������߷������浽������
	ways[0] = 1;
	ways[1] = 2;
	
	for (int i = 2; i < n; i++) {
		ways[i] = ways[i - 1] + ways[i - 2];
	}
	
	return ways[n - 1];
}

int main() {
	int n;
	cout << "������̨������" << endl;
	cin >> n;

	int count = climbWays(n);
	cout << "����" << count << "�ַ�ʽ��" << endl;
}