/*
* Ͱ���򣻹ؼ�����Ͱ�Ľ�����Ͱ�ķ�Χʵ�����Ǵ�����������е���ֵ��Χ��������Ϊ
          0-max�е������������Ӧ�����´洢��Ԫ��ʵ�����ǵ��ڸ�ֵ�����ָ�����
		  Ͱ������ɺ����ݾ���������ˣ�������Ҫ���ľ������ΰ�Ͱ�е�����ȡ������
*/

#include <iostream>
#include <vector>

using namespace std;

void bucketSort(vector<int>& arr) {
	int length = arr.size();  //���鳤��

	//��ȡ�����е����ֵ
	int a_max = arr[0];
	for (int i = 1; i < length - 1; i++) {
		if (a_max < arr[i]) {
			a_max = arr[i];
		}
	}

	//�������ֵ��Ͱ������ֵ
	vector<int> bucket(a_max + 1);
	for (int i = 0; i < arr.size(); i++) {
		bucket[arr[i]]++;
	}

	//����Ͱ��������
	for (int i = 0,j = 0; i < a_max + 1; i++) {  //����Ͱ
		while (bucket[i]-- > 0) {  //Ͱ�е�Ԫ����ԭ������ֵΪi�ĸ�����ÿ��ȡһ�������ȥһ��
			arr[j++] = i;
		}
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
	bucketSort(arr);

	//���
	cout << "�����Ľ��Ϊ��" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}