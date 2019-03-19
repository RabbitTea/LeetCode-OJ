/*
* 冒泡排序，实现由小到大排序；
* 思想：遍历若干次待排序的数列，每次遍历，都从前往后依次比较[相邻]两个数的大小；
        如果前者大于后者则交换，这样就会依次将最大的元素冒泡到数列的末尾。
		内部循环只用增长到i处，因为i每前进一位，就意味着后面已经有i个数已排好序，后面的不再需要比较。
		外部循环控制遍历的趟数，执行n-1(n为数组的大小)即可，因为只剩一个元素时是已排好序的。
* 性能：时间复杂度为O(N^2)；若比较条件中不添加"="，则算法是稳定的。
*/

#include <iostream>
#include <vector>

using namespace std;

/*
* 原始的冒泡排序
*/
/*
void bubbleSort(vector<int>& arr) {
	for (int i = arr.size() - 1; i > 0; i--) {  //这里i>0是为了遍历n-1次
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
*/


/*
* 对冒泡排序进行优化；
* 原因：i控制遍历的趟数，执行n-1次遍历，但有时排序算法执行到后边时，
        数据已经有序，则后边几趟都不需要进行数据交换。
* 方法：添加一个表示交换的标记，这个标记针对的是[每一趟]，即外部i循环中，
        如果一趟遍历中发生了交换，则标记为true，否则为false；
		若没有发生交换，则说明排序已完成，提前退出可提高效率。
*/
void bubbleSort(vector<int>& arr) {  //△注意这里一定要用引用，否则数组的值没有变化，改变的仅是函数中的临时变量
	bool flag;  //交换标记

	for (int i = arr.size() - 1; i > 0; i--) {
		flag = false;  //若没有发生交换则该值不改变

		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				flag = true;  //表示发生了交换
			}
		}

		if (!flag) {  //若没有交换则说明有序，直接退出
			break;
		}
	}
}

int main() {
	vector<int> arr;
	int num;
	while (cin >> num) {
		arr.push_back(num);
	}

	//排序
	bubbleSort(arr);

	//输出
	cout << "排序后结果为：" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}