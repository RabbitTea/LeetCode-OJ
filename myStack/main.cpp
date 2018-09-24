/**
* 栈的测试程序
*/
#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main()
{
    /**
    * 理解：C++中使用类对象要创建成指针的方式，通过->来进行变量和方法调用；
    *       而Java中直接用类创建对象，不需要用指针；
    */
    ArrayStack<int,10> *mystack = new ArrayStack<int,10>();
    int key = 0; //用于保存栈顶元素
    int s_size = 0; // 用于保存栈中元素的个数

    //将特定元素依次推入栈中
    mystack -> push(5);
    mystack -> push(10);
    mystack -> push(15);

    //删除栈顶元素并返回给key
    key = mystack -> pop();
    cout << "key=" << key << endl;

    //返回栈顶元素
    key = mystack -> peek();

    mystack -> push(20);
    //获取栈中元素的个数
    s_size = mystack -> stackSize();
    cout << "size=" << s_size << endl;

    while(!mystack->isEmpty()){
        key = mystack -> pop();
        cout << key << endl;
    }
    return 0;
}
