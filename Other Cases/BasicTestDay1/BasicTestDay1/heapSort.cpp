/*
* 堆排序：以最大堆为例；
* 涉及的操作：向下调整堆；构建最大堆(==插入元素)；删除堆顶元素
*/
#include <iostream>
#include <vector>

using namespace std;

//从第i个位置向下调整堆
void adjustUp2Down(vector<int>& nums, int i) {
	if (i < 0 || i >= nums.size()) {
		return;
	}

	int left = 2 * i;  //i左孩子的位置
	int right = 2 * i + 1;  //i右孩子的位置
	if (left >= nums.size() || right >= nums.size()) {
		return;
	}
	int max_idx = i;

	if (nums[i] < nums[left]) {
		max_idx = left;
	}
	if (nums[left] < nums[right]) {
		max_idx = right;
	}

	//如果i指向的元素不是最大者，则交换i和最大者，并递归调整，否则已经符合最大堆性质，不需要继续向下
	if (max_idx != i) {
		int temp = nums[i];
		nums[i] = nums[max_idx];
		nums[max_idx] = temp;
		adjustUp2Down(nums, max_idx);  //递归继续向下调整
	}
}

//构建最大堆
void create(vector<int>& nums) {
	if (nums.empty()) {
		cout << "堆不能为空！" << endl;
	}
	
	int len = nums.size();
	for (int i = (len + 1) / 2 - 1; i >= 0; i--) {
		adjustUp2Down(nums, i);  //向下调整堆
	}

	/*
	cout << "建堆" << endl;
	for (int i = 0; i < len; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	*/
}


//删除堆顶元素
int remove(vector<int>& nums) {
	//交换数组头元素和数组尾元素
	int max = nums[0]; //最大元素
	nums[0] = nums[nums.size() - 1];
	nums.pop_back();

	adjustUp2Down(nums, 0);

	return max;
}


//堆排序
void heap_sort(vector<int>& nums) {
	//建最小堆
	create(nums);

	while (!nums.empty()) {
		int max = remove(nums);
		cout << max << " ";
	}
}


/*
inline void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


void heapSort(vector<int>& nums) {
	create(nums);

	int len = nums.size();

	//这里不需要pop_back，因为这样会删除原数组，这里直接对原数组做修改，返回排好序的数组
	for (int i = len - 1; i >= 0; i--) {
		//交换堆顶和最后一个位置的元素
		swap(nums[0], nums[i]);

		adjustUp2Down(nums, 0);

	}

	//输出排好序的数组
	for (int i = 0; i < len; i++) {
		cout << nums[i] << " ";
	}
}
*/

int main() {
	vector<int> nums;
	int num;

	cout << "请输入待排序的元素：" << endl;

	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	cout << "排序后元素为：" << endl;
	heap_sort(nums);
}
