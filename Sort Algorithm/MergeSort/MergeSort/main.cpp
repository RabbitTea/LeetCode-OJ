/*
* @Description����·�鲢���򣻻��ڷ��β��ԣ�
                ������ʵ�ַ�ʽ����������(��Ҫʹ�õݹ�)����������
*/

#include <iostream>
#include <vector>

using namespace std;

/*
* ��������ʵ�֣�
*/
//�ϲ������������������ź����������ϲ�Ϊһ��[�����]���飺ͨ�����������е�ֵ���αȽϵķ�ʽ
//��Ҫ����Ĵ洢�ռ䣬��ϲ�����ͬ�ȴ�С
void merge(vector<int>& arr, int low, int mid, int high) {
	int length = high - low + 1;  //����������С
	vector<int> temp(length);   //����һ����СΪlength������

	//�趨����������Ŀ�ͷָ��
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

	//���ź��������ȫ�����ϵ�ԭ������(����temp������±꣬�����ź��Ĳ��־͸����Ĳ���)
	for (i = 0; i < k; i++) {
		arr[low + i] = temp[i];
	}
}

void mergeSortUp2Down(vector<int>& arr, int low, int high) {
	//���������ж�
	if (arr.empty() || low >= high) {
		return;
	}

	int mid = (high + low) / 2;
	mergeSortUp2Down(arr, low, mid);    //�ݹ�����arr[low...mid]
	mergeSortUp2Down(arr, mid + 1, high);     //�ݹ�����arr[mid+1...high]

	merge(arr, low, mid, high);   //�ϲ���һ������ռ�arr[low...high]
}


int main() {
	cout << "���������������飺" << endl;
	vector<int> arr;
     
	int num;
	/*
	* ���ֶ����Ǵ���ģ��ܻᶪ��һ������������Ϊcin.get()���ȡ�ո�ͻ��з���
	* �ڵ�һ��cin>>numʱ���Ѿ���ȡ�˵�һ���ַ������ǲ�û�н��䱣������.
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

	//����
	int low = 0;
	int high = arr.size() - 1;
	mergeSortUp2Down(arr, low, high);

	//���
	cout << "�������Ϊ��" << endl;
	int length = arr.size();
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}