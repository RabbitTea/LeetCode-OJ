#include <iostream>
#include <stack>

using namespace std;

/**
* 栈的实现与测试
* 说明：使用C++ STL中自带的stack
*
* @author Sandra
* @date 2018/9/24
*/

int main()
{
    int key = 0; // key用来保存弹出的栈顶元素的值
    stack<int> mystack;

    //将元素进栈
    mystack.push(5);
    mystack.push(10);
    mystack.push(15);

    //弹出栈顶元素，并返回给key
    mystack.pop();
    //cout << "当前key=" << key << endl;

    //返回栈顶元素的值
    key = mystack.top();

    mystack.push(20);

    while(!mystack.empty()){
        key = mystack.top();
        mystack.pop();
        cout << "key=" << key << endl;
    }
    return 0;
}
