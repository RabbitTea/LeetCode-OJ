/*
* @Description：二路归并排序；基于分治策略；
                有两种实现方式：从上往下(需要使用递归)，从下往上
*/

#include <iostream>
#include <vector>

using namespace std;

/*
* 从上往下实现；
*/
//合并操作，负责将两个已排好序的子数组合并为一个[有序的]数组：通过两个数组中的值依次比较的方式
//需要额外的存储空间，与合并数组同等大小
void merge(vector<int>& arr, int low, int mid, int high) {
	int length = high - low + 1;  //额外的数组大小
	vector<int> temp(length);   //申请一个大小为length的数组

	//设定两个子数组的开头指针
	int i = low;
	int j = mid + 1;
	int k = 0;
	
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= high) {
		temp[k++] = arr[j++];
	}

	//将排好序的数组全部整合到原数组中(根据temp数组的下标，即已排好哪部分就覆盖哪部分)
	for (i = 0; i < k; i++) {
		arr[low + i] = temp[i];
	}
}

void mergeSortUp2Down(vector<int>& arr, int low, int high) {
	//错误条件判断
	if (arr.empty() || low >= high) {
		return;
	}

	int mid = (high + low) / 2;
	mergeSortUp2Down(arr, low, mid);    //递归排序arr[low...mid]
	mergeSortUp2Down(arr, mid + 1, high);     //递归排序arr[mid+1...high]

	merge(arr, low, mid, high);   //合并成一个有序空间arr[low...high]
}


int main() {
	cout << "请输入待排序的数组：" << endl;
	vector<int> arr;
     
	int num;
	/*
	* 这种读法是错误的，总会丢掉一个数；这是因为cin.get()会读取空格和换行符，
	* 在第一处cin>>num时，已经读取了第一个字符，但是并没有将其保存下来.
	while (cin >> num) {
		if (cin.get() != '\n') {
			arr.push_back(num);
		}
	}
	*/
	while (cin >> num) {
		arr.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	//排序
	int low = 0;
	int high = arr.size() - 1;
	mergeSortUp2Down(arr, low, high);

	//输出
	cout << "排序后结果为：" << endl;
	int length = arr.size();
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}