/*ð������*/

#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& nums) {
	for (int i = nums.size() - 1; i > 0; i--) {  //iָʾ���ź����Ԫ���������Ӻ���ǰ��
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
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
	bubble_sort(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}
*/