/*
* ���ݽṹ�����С������鷽ʽʵ�֣�
* C++ģ����ʵ��
*/

#include <iostream>

using namespace std;

template<typename T> class Queue {
private:
	T* arr;          //�洢����Ԫ�ص�����ṹ
	int first;       //ָʾ��ͷԪ�ص��±�
	int rear;        //ָʾ��βԪ�ص��±�
	int q_length;    //���еĴ�С����ʼ�̶�
	int q_size;      //������Ԫ�صĸ���

public:
	Queue(int length = 8);   //���캯����Ĭ�ϸ�ֵӦ����������
	~Queue();            //��������
	void push(T val);    //Ԫ����ӣ���ӵ���β
	void pop();          //��ͷԪ�س��ӣ�������ֵ
	T front();           //���ض�ͷԪ��
	T back();            //���ض�βԪ��
	int isEmpty();       //�ж϶����Ƿ�Ϊ��
	int getSize();        //���ض�����Ԫ�صĸ���
};


//���캯����������еĴ�С
template<typename T>
Queue<T>::Queue(int length) {
	q_length = length;

	//�����з���ռ�
	arr = new T[q_length];
	
	//���Ը���ֵ
	first = 0;
	rear = -1;    //��ͷ����β��ָ���ͷǰһ��Ԫ��
	q_size = 0;      //��ʼ����Ϊ��
}


//��������
template<typename T>
Queue<T>::~Queue() {
	for (int i = 0; i < q_size; i++) {
		delete arr[i];
	}
}


//�ж϶����Ƿ�Ϊ��
template<typename T>
int Queue<T>::isEmpty() {
	if (rear == first == -1 || arr == NULL || q_size == 0) {
		return true;
	}
	else {
		return false;
	}
}


//Ԫ����ӣ���ӵ���β
template<typename T>
void Queue<T>::push(T val) {
	if (arr == NULL || rear == q_length) {
		cout << "queue error" << endl;
	}
	else {
		rear++;
		arr[rear] = val;
		q_size++;
	}
}


//��ͷԪ�س��ӣ�������ֵ
template<typename T>
void Queue<T>::pop() {
	if (!isEmpty()) {
		T firstVal = arr[first];
		first++;
		q_size--;
	}
	else {
		cout << "����Ϊ��!" << endl;
	}
}


//ȡ�ö�ͷԪ�ص�ֵ
template<typename T>
T Queue<T>::front() {
	T x;
	if (!isEmpty()) {
		x = arr[first];
	}
	return x;
}


//ȡ�ö�βԪ�ص�ֵ
template<typename T>
T Queue<T>::back() {
	T x;
	if (!isEmpty()) {
		x = arr[rear];
	}
	return x;
}


//���ض�����Ԫ�صĸ���
template<typename T>
int Queue<T>::getSize() {
	if (arr != NULL) {
		return q_size;
	}
}


int main() {
	Queue<int> *q = new Queue<int>(10);    //������СΪ10�Ķ���

	//���
	cout << "Ԫ�����" << endl;
	q->push(7);
	q->push(8);
	q->push(9);

    //ȡ�õ�ǰ��ͷԪ��
	cout << "��ǰ��ͷԪ��Ϊ��" << q->front() << endl;

	//ȡ�õ�ǰ��βԪ��
	cout << "��ǰ��βԪ��Ϊ��" << q->back() << endl;

	//��ͷԪ�س���
	q->pop();
	cout << "���Ӻ��ͷԪ��Ϊ��" << q->front() << endl;
}