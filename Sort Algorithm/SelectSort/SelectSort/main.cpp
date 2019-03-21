/*
* ѡ�����򣻹���˼�壬ÿ�δ�δ�����������ѡ����С(���)�ߣ�����ŵ����ź���������ĩβ��
*/

#include <iostream>
#include <vector>

using namespace std;

void selectSort(vector<int>& arr) {
	int length = arr.size();  //���鳤��

	int min_index;   //������С��

	for (int i = 0; i < length; i++) {
		min_index = i;  //��ʼ��С����Ϊδ��������ĵ�һ��

		for (int j = i + 1; j < length; j++) {  //�������������飬�ҵ���Сֵ���ڵ�����
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}

		//����Сֵ���ź����ĩβ��һ��Ԫ��(δ����ĵ�һ��Ԫ��)������
		int tmp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = tmp;
	}
}

int main() {
	cout << "���������������飺" << endl;
	vector<int> arr;
	int num;

	while (cin >> num) {
		arr.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	//����
	selectSort(arr);

	//���
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}