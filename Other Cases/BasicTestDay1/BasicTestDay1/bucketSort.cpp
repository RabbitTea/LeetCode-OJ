/*Ͱ����*/

#include <iostream>
#include <vector>

using namespace std;

void bucket_sort(vector<int>& nums) {
	//�ҵ������е����ֵ
	int max = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}

	//�������ֵ����һ�����飬������ÿ��λ�ó�Ϊһ��Ͱ
	vector<int> buckets(max+1);

	//��������Ԫ�ط����Ӧ��Ͱ��
	for (int i = 0; i < nums.size(); i++) {
		buckets[nums[i]]++;
	}

	//Ͱ����
	for (int k = 0; k < buckets.size(); k++) {
		while (buckets[k] > 0) {
			cout << k << " ";
			buckets[k]--;
		}
	}
}

/*
int main() {
	vector<int> nums;
	int num;

	cout << "���������������飺" << endl;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	cout << "����������Ϊ��" << endl;
	bucket_sort(nums);
}
*/