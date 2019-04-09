/*
* 在这里进行基本算法的练习，记录完成的时间，直到能用很短的时间做出来。
*/

#include <iostream>
#include <vector>

using namespace std;

/*快速排序*/
int partition(vector<int>& nums, int low, int high) {
	int pivot = nums[high];  //基准元素为数组最后一个元素

	int i = low - 1;  //注意这里i指向当前数组的最小下标的前一个位置
	int j;
	//int len = nums.size();

	if (low < high) {
		for (j = low; j <= high; j++) {
			if (nums[j] < pivot) {
				i++;
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
			}
		}

		i++;
		nums[high] = nums[i];
		nums[i] = pivot;

		return i;
	}
}

void quick_sort(vector<int>& nums, int low, int high) {
	if (low < high) {   //注意递归退出条件
		int len = nums.size();
		int idx_pivot = partition(nums, low, high);  //进行一次划分，得到当前数组基准元素的最终坐标
		quick_sort(nums, low, idx_pivot - 1);  //递归快排左边
		quick_sort(nums, idx_pivot + 1, high);  //递归快排右边
	}
}

/*
int main() {
	int num;
	vector<int> nums;
	cout << "请输入待排序的数组：" << endl;
	while (cin >> num) {
		nums.push_back(num);

		if (cin.get() == '\n') {
			break;
		}
	}

	//排序
	quick_sort(nums, 0, nums.size() - 1);

	cout << "排序后数组为：" << endl;
	for (int i = 0; i < nums.size();i++) {
		cout << nums[i] << " ";
	}
}
*/