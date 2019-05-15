/*
* ������������Ϊ����
* �漰�Ĳ��������µ����ѣ���������(==����Ԫ��)��ɾ���Ѷ�Ԫ��
*/
#include <iostream>
#include <vector>

using namespace std;

//�ӵ�i��λ�����µ�����
void adjustUp2Down(vector<int>& nums, int i) {
	if (i < 0 || i >= nums.size()) {
		return;
	}

	int left = 2 * i;  //i���ӵ�λ��
	int right = 2 * i + 1;  //i�Һ��ӵ�λ��
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

	//���iָ���Ԫ�ز�������ߣ��򽻻�i������ߣ����ݹ�����������Ѿ������������ʣ�����Ҫ��������
	if (max_idx != i) {
		int temp = nums[i];
		nums[i] = nums[max_idx];
		nums[max_idx] = temp;
		adjustUp2Down(nums, max_idx);  //�ݹ�������µ���
	}
}

//��������
void create(vector<int>& nums) {
	if (nums.empty()) {
		cout << "�Ѳ���Ϊ�գ�" << endl;
	}
	
	int len = nums.size();
	for (int i = (len + 1) / 2 - 1; i >= 0; i--) {
		adjustUp2Down(nums, i);  //���µ�����
	}

	/*
	cout << "����" << endl;
	for (int i = 0; i < len; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	*/
}


//ɾ���Ѷ�Ԫ��
int remove(vector<int>& nums) {
	//��������ͷԪ�غ�����βԪ��
	int max = nums[0]; //���Ԫ��
	nums[0] = nums[nums.size() - 1];
	nums.pop_back();

	adjustUp2Down(nums, 0);

	return max;
}


//������
void heap_sort(vector<int>& nums) {
	//����С��
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

	//���ﲻ��Ҫpop_back����Ϊ������ɾ��ԭ���飬����ֱ�Ӷ�ԭ�������޸ģ������ź��������
	for (int i = len - 1; i >= 0; i--) {
		//�����Ѷ������һ��λ�õ�Ԫ��
		swap(nums[0], nums[i]);

		adjustUp2Down(nums, 0);

	}

	//����ź��������
	for (int i = 0; i < len; i++) {
		cout << nums[i] << " ";
	}
}
*/

int main() {
	vector<int> nums;
	int num;

	cout << "������������Ԫ�أ�" << endl;

	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	cout << "�����Ԫ��Ϊ��" << endl;
	heap_sort(nums);
}
