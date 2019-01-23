/**
* 栈的C++实现一
* 说明——利用数组存储结构和C++的模板类手动实现简单的栈操作，能存储任意类型的数据；
* 注：因为本算法实现栈时利用了C++模板，而【C++编译器不能支持对模板的分离式编译】，所以栈的声明和实现都在头文件中；
*/
#ifndef ARRAYSTACK_H_INCLUDED
#define ARRAYSTACK_H_INCLUDED

#include <iostream>
#include "ArrayStack.h"
using namespace std;

//建立一个数组栈的模板类
//声明的方法在类外实现
template<typename T,int N> class ArrayStack{
public:
    ArrayStack(); // 无参构造函数
    ~ArrayStack(); // 析构函数

    void push(T t); // 将元素t压栈，无返回值
    T pop(); // 无参的出栈操作，返回弹出的元素值
    T peek(); // 返回栈顶元素值
    int isEmpty(); // 判断栈是否为空
    int stackSize(); // 获取栈中元素个数
private:
    T arr[N]; // 模板T的数组arr
    int top; // 指示栈顶元素的下标
    int s_size; // 指示栈中元素个数
};

//创建栈，默认大小为10
template<typename T,int N>
ArrayStack<T,N>::ArrayStack()
{
    //arr = new T[N];
    if(!arr){
        cout << "arr malloc error!" << endl; // 数组申请内存失败时的输出
    }
    top = -1;// top初始指示栈前一个位置的下标
    s_size = 0; // 初始栈为空
}

//销毁栈
template<typename T,int N>
ArrayStack<T,N>::~ArrayStack()
{
    if(arr){
        delete[] arr; // 删除数组的操作
        arr = NULL;
    }
}

//判断栈是否为空，为空返回true，非空返回false
template<typename T,int N>
int ArrayStack<T,N>::isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

//将元素t压栈，无返回值
template<typename T,int N>
void ArrayStack<T,N>::push(T t)
{
    //ArrayStack s;
    // 无需创建ArrayStack的类对象，因为方法在类中，可以直接使用类中的成员变量
    if(s_size < N){
        top++;
        arr[top] = t;
        ++s_size;
    }
    else
        cout << "overflow" << endl;
}

//弹出栈顶元素并返回元素值
template<typename T,int N>
T ArrayStack<T,N>::pop()
{
    if(isEmpty())
        cout << "underflow" << endl;
    T key = arr[top];
    top--;
    --s_size;
    return key;
}

//返回栈顶元素值
template<typename T,int N>
T ArrayStack<T,N>::peek()
{
    return arr[top];
}

//获取栈中元素的个数
template<typename T,int N>
int ArrayStack<T,N>::stackSize()
{
    return s_size;
}
#endif // ARRAYSTACK_H_INCLUDED
