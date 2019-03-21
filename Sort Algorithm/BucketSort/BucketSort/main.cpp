/*
* 桶排序；关键在于桶的建立，桶的范围实际上是待排序的数组中的数值范围，其索引为
          0-max中的正整数，其对应索引下存储的元素实际上是等于改值的数字个数，
		  桶建立完成后数据就是有序的了，接下来要做的就是依次把桶中的数据取出来。
*/

#include <iostream>
#include <vector>

using namespace std;

void bucketSort(vector<int>& arr) {
	int length = arr.size();  //数组长度

	//获取数组中的最大值
	int a_max = arr[0];
	for (int i = 1; i < length - 1; i++) {
		if (a_max < arr[i]) {
			a_max = arr[i];
		}
	}

	//根据最大值建桶，并存值
	vector<int> bucket(a_max + 1);
	for (int i = 0; i < arr.size(); i++) {
		bucket[arr[i]]++;
	}

	//根据桶进行排序
	for (int i = 0,j = 0; i < a_max + 1; i++) {  //遍历桶
		while (bucket[i]-- > 0) {  //桶中的元素是原数组中值为i的个数，每次取一个，便减去一个
			arr[j++] = i;
		}
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
	bucketSort(arr);

	//输出
	cout << "排序后的结果为：" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}