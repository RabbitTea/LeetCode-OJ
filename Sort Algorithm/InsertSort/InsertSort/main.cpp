/*
* ֱ�Ӳ������������ڳ��˿ˣ�ÿһ��(i)��ѡʣ�µ�δ����������е�[��һ��ֵ]���ŵ����ź����
                ����ĩβ���������ѡ��j���ȱ���j�е�ֵ��Ȼ����������ǰ����ź��������
				�е�ֵ�Ƚϣ����뵽������λ�á�
*/

#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int>& arr) {
	int length = arr.size();

	for (int i = 0; i < length-1; i++) {   //i����������飬��ʶ�ź����Ԫ�ظ���
		int j = i + 1;    //δ��������ĵ�һ����Ҫ����ֵ���뵽ǰ�����ź����������
		int cur = arr[j];
		
		while (j > 0 && cur < arr[j - 1]) {   //������ǰһ��ֵ�Ƚϣ���С����ǰ�ߵ�ֵ����
			arr[j] = arr[j - 1];
			j--;
		}

		arr[j] = cur;
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
	insertSort(arr);

	//���
	cout << "�������Ϊ��" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}