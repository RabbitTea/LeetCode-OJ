/*
* 数据结构：栈；  物理结构使用数组实现
* 使用C++的模板类来实现；
*/

#include <iostream>

using namespace std;


template<typename T> class ArrayStack {
private:
	T* arr;    //存储栈的数组结构
	int top;     //栈顶指针[指示栈顶元素的下标]
	int s_length;    //栈的大小
	int s_size;     //栈中元素的个数

public:
	ArrayStack(int length = 8);         //无参构造函数；默认参数应该用在函数的声明中，如果用户没有传参数，则使用默认的参数
	~ArrayStack();        //析构函数

	void push(T val);     //将元素压栈
	T pop();              //弹出栈顶元素
	T peek();             //返回栈顶元素值[该元素不出栈]
	int isEmpty();        //判断栈是否为空
	int getSize();      //得到栈中元素个数
};


//构造方法
template<typename T>
ArrayStack<T>::ArrayStack(int length) {

	s_length = length;     //规定栈的大小

	arr = new T[s_length];   //申请数组空间

	if (!arr) {
		cout << "内存申请失败" << endl;
	}

	top = -1;   //top初始指示栈前一个位置的下标
	s_size = 0;  //初始栈为空
}


//析构方法
template<typename T>
ArrayStack<T>::~ArrayStack() {
	for (int i = 0; i < s_size; i++) {
		delete arr[i];
	}
}


//判断栈是否为空，为空返回true，非空返回false
template<typename T>
int ArrayStack<T>::isEmpty() {
	if (arr == NULL || s_size == 0 || top == -1) {
		return true;
	}
	else {
		return false;
	}
}


//将元素压栈
template<typename T>
void ArrayStack<T>::push(T val) {
	if (arr == NULL || top == s_length) {   //判断栈存在且栈未满
		cout << "stack error!" << endl;
	}
	else {
		top++;  //栈顶指针加1
		arr[top] = val;    //元素入栈
		s_size++;     //元素个数增加
	}
}


//将栈顶元素出栈
template<typename T>
T ArrayStack<T>::pop() {
	T x;
	if (!isEmpty()) { //栈不空
		x = arr[top];

		top--;   //栈顶指针减一；这里不需要delete原来的位置，否则会缩小栈
		s_size--;   //栈中元素减少
	}

	return x;
}


//取得栈顶元素，但不出栈
template<typename T>
T ArrayStack<T>::peek() {
	T x;
	if (!isEmpty()) {
		x = arr[top];   //这里栈顶指针和栈中元素个数都不变
	}

	return x;
}


//返回栈中元素个数
template<typename T>
int ArrayStack<T>::getSize() {
	return s_size;
}

int main() {
	//用指针的方式创建类对象
	ArrayStack<int> *myStack = new ArrayStack<int>(10);    //创建一个大小为10的栈

	//入栈
	cout << "元素入栈" << endl;
	myStack->push(5);
	myStack->push(6);
	myStack->push(7);

	//栈顶元素
	cout << "当前栈顶元素为：" << myStack->peek() << endl;

	//出栈
	cout << "栈顶元素出栈" << " " ;
	cout << "元素为：" << myStack->pop() << endl;

	//栈顶元素
	cout << "出栈后当前栈顶元素为：" << myStack->pop() << endl;
}