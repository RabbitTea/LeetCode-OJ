/*
* ��������л����㷨����ϰ����¼��ɵ�ʱ�䣬ֱ�����ú̵ܶ�ʱ����������
*/

#include <iostream>
#include <vector>

using namespace std;

/*��������*/
int partition(vector<int>& nums, int low, int high) {
	int pivot = nums[high];  //��׼Ԫ��Ϊ�������һ��Ԫ��

	int i = low - 1;  //ע������iָ��ǰ�������С�±��ǰһ��λ��
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
	if (low < high) {   //ע��ݹ��˳�����
		int len = nums.size();
		int idx_pivot = partition(nums, low, high);  //����һ�λ��֣��õ���ǰ�����׼Ԫ�ص���������
		quick_sort(nums, low, idx_pivot - 1);  //�ݹ�������
		quick_sort(nums, idx_pivot + 1, high);  //�ݹ�����ұ�
	}
}

/*
int main() {
	int num;
	vector<int> nums;
	cout << "���������������飺" << endl;
	while (cin >> num) {
		nums.push_back(num);

		if (cin.get() == '\n') {
			break;
		}
	}

	//����
	quick_sort(nums, 0, nums.size() - 1);

	cout << "���������Ϊ��" << endl;
	for (int i = 0; i < nums.size();i++) {
		cout << nums[i] << " ";
	}
}
*/