/*
* ���ݽṹ��ջ��  ����ṹʹ������ʵ��
* ʹ��C++��ģ������ʵ�֣�
*/

#include <iostream>

using namespace std;


template<typename T> class ArrayStack {
private:
	T* arr;    //�洢ջ������ṹ
	int top;     //ջ��ָ��[ָʾջ��Ԫ�ص��±�]
	int s_length;    //ջ�Ĵ�С
	int s_size;     //ջ��Ԫ�صĸ���

public:
	ArrayStack(int length = 8);         //�޲ι��캯����Ĭ�ϲ���Ӧ�����ں����������У�����û�û�д���������ʹ��Ĭ�ϵĲ���
	~ArrayStack();        //��������

	void push(T val);     //��Ԫ��ѹջ
	T pop();              //����ջ��Ԫ��
	T peek();             //����ջ��Ԫ��ֵ[��Ԫ�ز���ջ]
	int isEmpty();        //�ж�ջ�Ƿ�Ϊ��
	int getSize();      //�õ�ջ��Ԫ�ظ���
};


//���췽��
template<typename T>
ArrayStack<T>::ArrayStack(int length) {

	s_length = length;     //�涨ջ�Ĵ�С

	arr = new T[s_length];   //��������ռ�

	if (!arr) {
		cout << "�ڴ�����ʧ��" << endl;
	}

	top = -1;   //top��ʼָʾջǰһ��λ�õ��±�
	s_size = 0;  //��ʼջΪ��
}


//��������
template<typename T>
ArrayStack<T>::~ArrayStack() {
	for (int i = 0; i < s_size; i++) {
		delete arr[i];
	}
}


//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���true���ǿշ���false
template<typename T>
int ArrayStack<T>::isEmpty() {
	if (arr == NULL || s_size == 0 || top == -1) {
		return true;
	}
	else {
		return false;
	}
}


//��Ԫ��ѹջ
template<typename T>
void ArrayStack<T>::push(T val) {
	if (arr == NULL || top == s_length) {   //�ж�ջ������ջδ��
		cout << "stack error!" << endl;
	}
	else {
		top++;  //ջ��ָ���1
		arr[top] = val;    //Ԫ����ջ
		s_size++;     //Ԫ�ظ�������
	}
}


//��ջ��Ԫ�س�ջ
template<typename T>
T ArrayStack<T>::pop() {
	T x;
	if (!isEmpty()) { //ջ����
		x = arr[top];

		top--;   //ջ��ָ���һ�����ﲻ��Ҫdeleteԭ����λ�ã��������Сջ
		s_size--;   //ջ��Ԫ�ؼ���
	}

	return x;
}


//ȡ��ջ��Ԫ�أ�������ջ
template<typename T>
T ArrayStack<T>::peek() {
	T x;
	if (!isEmpty()) {
		x = arr[top];   //����ջ��ָ���ջ��Ԫ�ظ���������
	}

	return x;
}


//����ջ��Ԫ�ظ���
template<typename T>
int ArrayStack<T>::getSize() {
	return s_size;
}

int main() {
	//��ָ��ķ�ʽ���������
	ArrayStack<int> *myStack = new ArrayStack<int>(10);    //����һ����СΪ10��ջ

	//��ջ
	cout << "Ԫ����ջ" << endl;
	myStack->push(5);
	myStack->push(6);
	myStack->push(7);

	//ջ��Ԫ��
	cout << "��ǰջ��Ԫ��Ϊ��" << myStack->peek() << endl;

	//��ջ
	cout << "ջ��Ԫ�س�ջ" << " " ;
	cout << "Ԫ��Ϊ��" << myStack->pop() << endl;

	//ջ��Ԫ��
	cout << "��ջ��ǰջ��Ԫ��Ϊ��" << myStack->pop() << endl;
}