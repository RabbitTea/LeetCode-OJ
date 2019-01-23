/**
* ջ��C++ʵ��һ
* ˵��������������洢�ṹ��C++��ģ�����ֶ�ʵ�ּ򵥵�ջ�������ܴ洢�������͵����ݣ�
* ע����Ϊ���㷨ʵ��ջʱ������C++ģ�壬����C++����������֧�ֶ�ģ��ķ���ʽ���롿������ջ��������ʵ�ֶ���ͷ�ļ��У�
*/
#ifndef ARRAYSTACK_H_INCLUDED
#define ARRAYSTACK_H_INCLUDED

#include <iostream>
#include "ArrayStack.h"
using namespace std;

//����һ������ջ��ģ����
//�����ķ���������ʵ��
template<typename T,int N> class ArrayStack{
public:
    ArrayStack(); // �޲ι��캯��
    ~ArrayStack(); // ��������

    void push(T t); // ��Ԫ��tѹջ���޷���ֵ
    T pop(); // �޲εĳ�ջ���������ص�����Ԫ��ֵ
    T peek(); // ����ջ��Ԫ��ֵ
    int isEmpty(); // �ж�ջ�Ƿ�Ϊ��
    int stackSize(); // ��ȡջ��Ԫ�ظ���
private:
    T arr[N]; // ģ��T������arr
    int top; // ָʾջ��Ԫ�ص��±�
    int s_size; // ָʾջ��Ԫ�ظ���
};

//����ջ��Ĭ�ϴ�СΪ10
template<typename T,int N>
ArrayStack<T,N>::ArrayStack()
{
    //arr = new T[N];
    if(!arr){
        cout << "arr malloc error!" << endl; // ���������ڴ�ʧ��ʱ�����
    }
    top = -1;// top��ʼָʾջǰһ��λ�õ��±�
    s_size = 0; // ��ʼջΪ��
}

//����ջ
template<typename T,int N>
ArrayStack<T,N>::~ArrayStack()
{
    if(arr){
        delete[] arr; // ɾ������Ĳ���
        arr = NULL;
    }
}

//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���true���ǿշ���false
template<typename T,int N>
int ArrayStack<T,N>::isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

//��Ԫ��tѹջ���޷���ֵ
template<typename T,int N>
void ArrayStack<T,N>::push(T t)
{
    //ArrayStack s;
    // ���贴��ArrayStack���������Ϊ���������У�����ֱ��ʹ�����еĳ�Ա����
    if(s_size < N){
        top++;
        arr[top] = t;
        ++s_size;
    }
    else
        cout << "overflow" << endl;
}

//����ջ��Ԫ�ز�����Ԫ��ֵ
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

//����ջ��Ԫ��ֵ
template<typename T,int N>
T ArrayStack<T,N>::peek()
{
    return arr[top];
}

//��ȡջ��Ԫ�صĸ���
template<typename T,int N>
int ArrayStack<T,N>::stackSize()
{
    return s_size;
}
#endif // ARRAYSTACK_H_INCLUDED
