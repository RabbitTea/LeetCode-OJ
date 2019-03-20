/*
* ��������ʵ����С��������
* ˼�룺���÷��β��ԣ�ѡ��һ����׼��(�����е�һ�������һ������)��ͨ��һ������Ҫ
        ��������ݷֳɶ����������֣�ǰһ�������ݾ�С�ڻ�׼������һ�������ݾ����ڻ�׼����
		�ٵݹ����ͬ���ķ�ʽ�����������֡�ʵ���Ͽ��ŷ�Ϊpartition��sort����������partition
		����ѡ���׼�����������飬����׼�ŵ����յ�λ���ϡ�
*/

#include <iostream>
#include <vector>

using namespace std;


/*
* ��շ�ʵ�֣���Ĭ�ϻ�׼��������λ��Ϊ��(����ѡȡ�Ļ�׼�������鿪ͷԪ��)��[��������]������[��������]����������У�
              ���������Ŀ�����ҵ��Ȼ�׼��С���������ν����������鿪ͷ����λ��(��ʼ����ָ�ڿ�ͷλ��)��
			  �������ҵ�Ŀ�����ҵ��Ȼ�׼������������ν�������ָ����ָ��ǰһ��λ�á�
			  ���ǰָ��λ�ô������׼����
*/
/*
void quickSort(vector<int>& arr, int l, int r) {  //ע������Ҫ������
	//l��r�ֱ��ʾ����Ŀ�ͷԪ�غ�ĩβԪ��
	if (l < r)   //������һ��Ҫ�Ӹ��жϣ���Ϊ�ݹ��п��ܿ�ͷ�ͽ�β��ֵ��ȡ�
	{
		int pivot = arr[l];  //������(����������)�еĿ�ͷԪ������Ϊ��׼��

		int i = l;  //ǰָ�룬�����ǰ������
		int j = r;  //��ָ�룬����Ӻ���ǰ����

		while (i < j) {  //��ָ���������ôλ��ֽ���
			while (i < j && arr[j] > pivot)   //�Ӻ���ǰ�ҵ���pivotС����
				j--;
			//�ҵ�֮���򽻻�
			if (i < j)
				arr[i++] = arr[j];     //�� ע�������Ƚ���arr[i]�ĸ�ֵ����ִ��i����������Ϊ������i��ʱָ���ֵ�㲻��Ҫ�ٶ���
			while (i < j && arr[i] < pivot)   //��ǰ�����ҵ���pivot�����
				i++;
			//�ҵ�֮���򽻻�
			if (i < j)
				arr[j--] = arr[i];
		}
		//�ôλ��ֽ����󣬽���׼���ŵ�������λ����
		arr[i] = pivot;

		//�ݹ��ǰ������������ֱ�ִ�п����㷨
		quickSort(arr, l, i - 1);
		quickSort(arr, i + 1, r);
	}
}
*/


/*
* ��һ����շ���ʵ�ַ�ʽ����ѡȡ���鿪ͷԪ��Ϊ��׼�������䱣�浽һ�������У���ǰ�������Ҫ����ʱ����һ���Ƚ���ͷԪ��
                          ��ֵ���ǵ��������������˿գ�����ٰѱ���Ļ�׼�������λ�á�
						  �����Ϊpartition������sort������д��partition�������𻮷����飬���ظôλ��ֺ��׼�����ڵ�������
*/
/*
int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[low];   //ѡȡ���鿪ͷԪ��Ϊ��׼��

	while (low < high) {
		while (low < high && arr[high] > pivot)   //�� ����������׼���ȽϵĲ���д<������Ķ�Ӧλ��д>������ʵ���ɴ�С����
			high--;
		arr[low] = arr[high];
		while (low < high && arr[low] < pivot)
			low++;
		arr[high] = arr[low];
	}
	//low==high���˳�ѭ������ʱǰ��ָ��ָ��ͬһλ�ã��ڸ�λ�÷����׼��
	arr[low] = pivot;

	return low;
}

void quickSort(vector<int>& arr, int low, int high) {
	if (low < high) {  //������жϣ�����ݹ麯�������low��high��ȵ����
		int index = partition(arr, low, high);
		//�ݹ���л�׼��ǰ������������Ŀ�������
		quickSort(arr, low, index - 1);
		quickSort(arr, index + 1, high);
	}
}
*/


/*
* ʵ�ַ�������ǰ��ָ�뷨����������������i,j����ʼ�ֱ�ָ�����鿪ͷǰһ��λ�ú����鿪ͷλ�ã�
              ����iʼ��ָʾ��С�����±�λ�ã���j�������һ�����飬��ָʾ����ֵ���׼���Ƚϣ�
			  ÿ����һ����С�߾ͽ���i������ָ���λ�õ�ֵ���н�����
*/
int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[high];   //��ע������Ҫѡ�����һ������Ϊ��׼
	//ָ��ָʾ��С����ָ��
	int i = low - 1;

	for (int j = low; j < arr.size() - 1; j++) {
		if (arr[j] < pivot) {
			i++;  //iҪ�Ƚ�������

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
	if (low < high) {  //������жϣ�����ݹ麯�������low��high��ȵ����
		int index = partition(arr, low, high);
		//�ݹ���л�׼��ǰ������������Ŀ�������
		quickSort(arr, low, index - 1);
		quickSort(arr, index + 1, high);
	}
}


int main() {
	vector<int> arr;
	cout << "���������������飺" << endl;

	//����
	int num;
	while (cin >> num) {
		arr.push_back(num);
		if (cin.get() == '\n')
		{
			break;
		}
	}

	//����
	quickSort(arr, 0, arr.size() - 1);

	//���
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}