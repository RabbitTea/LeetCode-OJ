/*
* 快速排序，实现由小到大排序；
* 思想：采用分治策略；选择一个基准数(数组中第一个或最后一个均可)，通过一趟排序将要
        排序的数据分成独立的两部分：前一部分数据均小于基准数，后一部分数据均大于基准数；
		再递归地用同样的方式处理这两部分。实际上快排分为partition和sort两步，其中partition
		负责选择基准，并划分数组，将基准放到最终的位置上。
*/

#include <iostream>
#include <vector>

using namespace std;


/*
* 填空法实现：即默认基准数所处的位置为空(∵所选取的基准数是数组开头元素)，[从右往左]遍历和[从左往右]遍历交替进行，
              从右往左的目的是找到比基准数小的数，依次交换到从数组开头向后的位置(初始索引指在开头位置)；
			  从左往右的目的是找到比基准数大的数，依次交换到后指针所指的前一个位置。
			  最后前指针位置处放入基准数。
*/
/*
void quickSort(vector<int>& arr, int l, int r) {  //注意这里要传引用
	//l和r分别表示数组的开头元素和末尾元素
	if (l < r)   //△这里一定要加个判断，因为递归有可能开头和结尾的值相等。
	{
		int pivot = arr[l];  //将数组(或者子数组)中的开头元素设置为基准数

		int i = l;  //前指针，负责从前向后遍历
		int j = r;  //后指针，负责从后向前遍历

		while (i < j) {  //两指针相遇，该次划分结束
			while (i < j && arr[j] > pivot)   //从后往前找到比pivot小的数
				j--;
			//找到之后则交换
			if (i < j)
				arr[i++] = arr[j];     //△ 注意这里先进行arr[i]的赋值，再执行i的自增，因为交换后i此时指向的值便不需要再动了
			while (i < j && arr[i] < pivot)   //从前往后找到比pivot大的数
				i++;
			//找到之后则交换
			if (i < j)
				arr[j--] = arr[i];
		}
		//该次划分结束后，将基准数放到其最终位置上
		arr[i] = pivot;

		//递归对前后两个子数组分别执行快排算法
		quickSort(arr, l, i - 1);
		quickSort(arr, i + 1, r);
	}
}
*/


/*
* 另一种填空法的实现方式，即选取数组开头元素为基准数，将其保存到一个变量中，在前后遍历需要交换时，第一次先将开头元素
                          的值覆盖掉，这样就留出了空，最后再把保存的基准数填到最终位置。
						  这里分为partition函数和sort函数来写，partition函数负责划分数组，返回该次划分后基准数所在的索引。
*/
/*
int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[low];   //选取数组开头元素为基准数

	while (low < high) {
		while (low < high && arr[high] > pivot)   //△ 如果这里与基准数比较的部分写<，下面的对应位置写>，最后会实现由大到小排序
			high--;
		arr[low] = arr[high];
		while (low < high && arr[low] < pivot)
			low++;
		arr[high] = arr[low];
	}
	//low==high，退出循环，此时前后指针指向同一位置，在该位置放入基准数
	arr[low] = pivot;

	return low;
}

void quickSort(vector<int>& arr, int low, int high) {
	if (low < high) {  //必须加判断，否则递归函数会出现low和high相等的情况
		int index = partition(arr, low, high);
		//递归进行基准数前后两部分数组的快速排序
		quickSort(arr, low, index - 1);
		quickSort(arr, index + 1, high);
	}
}
*/


/*
* 实现方法二：前后指针法；即设置两个索引i,j，初始分别指向数组开头前一个位置和数组开头位置，
              这样i始终指示较小数的下标位置，而j负责遍历一遍数组，将指示到的值与基准数比较，
			  每遇到一个较小者就将与i自增后指向的位置的值进行交换。
*/
int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[high];   //△注意这里要选择最后一个数作为基准
	//指定指示较小数的指针
	int i = low - 1;

	for (int j = low; j < arr.size() - 1; j++) {
		if (arr[j] < pivot) {
			i++;  //i要先进行自增

			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}

	i++;
	int temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;

	return i;
}

void quickSort(vector<int>& arr, int low, int high) {
	if (low < high) {  //必须加判断，否则递归函数会出现low和high相等的情况
		int index = partition(arr, low, high);
		//递归进行基准数前后两部分数组的快速排序
		quickSort(arr, low, index - 1);
		quickSort(arr, index + 1, high);
	}
}


int main() {
	vector<int> arr;
	cout << "请输入待排序的数组：" << endl;

	//输入
	int num;
	while (cin >> num) {
		arr.push_back(num);
		if (cin.get() == '\n')
		{
			break;
		}
	}

	//排序
	quickSort(arr, 0, arr.size() - 1);

	//输出
	cout << "排序后的数组为：" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}