/*归并排序*/
#include <iostream>
#include <vector>

using namespace std;

//注意这里为二路归并排序，即传入两个待合并的数组是相连的，传入头索引，尾索引和中间索引即可
void merge(vector<int>& nums, int low, int mid, int high) {
	int len = high - low +1;
	vector<int> temp(len);

	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high) {
		if (nums[i] <= nums[j]) {
			temp[k++] = nums[i++];
		}
		else {
			temp[k++] = nums[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = nums[i++];
	}
	while (j <= high) {
		temp[k++] = nums[j++];
	}

	//用合并后的数组替换原数组对应位置的元素
	for (int i = 0; i < k; i++) {
		nums[low + i] = temp[i];
	}
}


void merge_sort(vector<int>& nums, int low, int high) {
	if (low < high) {
		int mid = (high + low) / 2;
		merge_sort(nums, low, mid);
		merge_sort(nums, mid + 1, high);
		merge(nums, low, mid, high);
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

	merge_sort(nums,0,nums.size()-1);

	cout << "排序后的数组为：" << endl;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}
*/