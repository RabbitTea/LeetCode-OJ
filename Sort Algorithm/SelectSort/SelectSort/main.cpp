/*
* 选择排序；顾名思义，每次从未排序的数组中选择最小(最大)者，将其放到已排好序的数组的末尾。
*/

#include <iostream>
#include <vector>

using namespace std;

void selectSort(vector<int>& arr) {
	int length = arr.size();  //数组长度

	int min_index;   //保存最小者

	for (int i = 0; i < length; i++) {
		min_index = i;  //初始最小索引为未排序数组的第一个

		for (int j = i + 1; j < length; j++) {  //遍历待排序数组，找到最小值所在的索引
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}

		//将最小值与排好序的末尾后一个元素(未排序的第一个元素)做交换
		int tmp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = tmp;
	}
}

int main() {
	cout << "请输入待排序的数组：" << endl;
	vector<int> arr;
	int num;

	while (cin >> num) {
		arr.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	//排序
	selectSort(arr);

	//输出
	cout << "排序后的数组为：" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}