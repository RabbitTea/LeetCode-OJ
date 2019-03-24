/*
* 数据结构：队列——数组方式实现；
* C++模板类实现
*/

#include <iostream>

using namespace std;

template<typename T> class Queue {
private:
	T* arr;          //存储队列元素的数组结构
	int first;       //指示队头元素的下标
	int rear;        //指示队尾元素的下标
	int q_length;    //队列的大小，初始固定
	int q_size;      //队列中元素的个数

public:
	Queue(int length = 8);   //构造函数，默认赋值应该在声明中
	~Queue();            //析构函数
	void push(T val);    //元素入队，添加到队尾
	void pop();          //队头元素出队，不返回值
	T front();           //返回队头元素
	T back();            //返回队尾元素
	int isEmpty();       //判断队列是否为空
	int getSize();        //返回队列中元素的个数
};


//构造函数，传入队列的大小
template<typename T>
Queue<T>::Queue(int length) {
	q_length = length;

	//给队列分配空间
	arr = new T[q_length];
	
	//属性赋初值
	first = 0;
	rear = -1;    //队头，队尾都指向队头前一个元素
	q_size = 0;      //初始队列为空
}


//析构函数
template<typename T>
Queue<T>::~Queue() {
	for (int i = 0; i < q_size; i++) {
		delete arr[i];
	}
}


//判断队列是否为空
template<typename T>
int Queue<T>::isEmpty() {
	if (rear == first == -1 || arr == NULL || q_size == 0) {
		return true;
	}
	else {
		return false;
	}
}


//元素入队，添加到队尾
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


//队头元素出队，不返回值
template<typename T>
void Queue<T>::pop() {
	if (!isEmpty()) {
		T firstVal = arr[first];
		first++;
		q_size--;
	}
	else {
		cout << "队列为空!" << endl;
	}
}


//取得队头元素的值
template<typename T>
T Queue<T>::front() {
	T x;
	if (!isEmpty()) {
		x = arr[first];
	}
	return x;
}


//取得队尾元素的值
template<typename T>
T Queue<T>::back() {
	T x;
	if (!isEmpty()) {
		x = arr[rear];
	}
	return x;
}


//返回队列中元素的个数
template<typename T>
int Queue<T>::getSize() {
	if (arr != NULL) {
		return q_size;
	}
}


int main() {
	Queue<int> *q = new Queue<int>(10);    //创建大小为10的队列

	//入队
	cout << "元素入队" << endl;
	q->push(7);
	q->push(8);
	q->push(9);

    //取得当前队头元素
	cout << "当前队头元素为：" << q->front() << endl;

	//取得当前队尾元素
	cout << "当前队尾元素为：" << q->back() << endl;

	//队头元素出队
	q->pop();
	cout << "出队后队头元素为：" << q->front() << endl;
}