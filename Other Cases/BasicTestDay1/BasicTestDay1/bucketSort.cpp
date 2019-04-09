/*桶排序*/

#include <iostream>
#include <vector>

using namespace std;

void bucket_sort(vector<int>& nums) {
	//找到数组中的最大值
	int max = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}

	//根据最大值建立一个数组，该数组每个位置称为一个桶
	vector<int> buckets(max+1);

	//将数组中元素放入对应的桶中
	for (int i = 0; i < nums.size(); i++) {
		buckets[nums[i]]++;
	}

	//桶排序
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

	cout << "请输入待排序的数组：" << endl;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	cout << "排序后的数组为：" << endl;
	bucket_sort(nums);
}
*/