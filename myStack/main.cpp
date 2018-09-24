/**
* ջ�Ĳ��Գ���
*/
#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main()
{
    /**
    * ��⣺C++��ʹ�������Ҫ������ָ��ķ�ʽ��ͨ��->�����б����ͷ������ã�
    *       ��Java��ֱ�����ഴ�����󣬲���Ҫ��ָ�룻
    */
    ArrayStack<int,10> *mystack = new ArrayStack<int,10>();
    int key = 0; //���ڱ���ջ��Ԫ��
    int s_size = 0; // ���ڱ���ջ��Ԫ�صĸ���

    //���ض�Ԫ����������ջ��
    mystack -> push(5);
    mystack -> push(10);
    mystack -> push(15);

    //ɾ��ջ��Ԫ�ز����ظ�key
    key = mystack -> pop();
    cout << "key=" << key << endl;

    //����ջ��Ԫ��
    key = mystack -> peek();

    mystack -> push(20);
    //��ȡջ��Ԫ�صĸ���
    s_size = mystack -> stackSize();
    cout << "size=" << s_size << endl;

    while(!mystack->isEmpty()){
        key = mystack -> pop();
        cout << key << endl;
    }
    return 0;
}
