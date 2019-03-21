/*
* 直接插入排序；类似于抽扑克；每一趟(i)都选剩下的未排序的数组中的[第一个值]，放到已排好序的
                数组末尾；这里就是选中j后，先保存j中的值，然后将其依次与前面的排好序的数组
				中的值比较，插入到其最终位置。
*/

#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int>& arr) {
	int length = arr.size();

	for (int i = 0; i < length-1; i++) {   //i负责遍历数组，标识排好序的元素个数
		int j = i + 1;    //未排序数组的第一个，要将该值插入到前边已排好序的序列中
		int cur = arr[j];
		
		while (j > 0 && cur < arr[j - 1]) {   //依次与前一个值比较，若小于则将前边的值后移
			arr[j] = arr[j - 1];
			j--;
		}

		arr[j] = cur;
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
	insertSort(arr);

	//输出
	cout << "排序后结果为：" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}