#include <iostream>
#include <stack>

using namespace std;

/**
* ջ��ʵ�������
* ˵����ʹ��C++ STL���Դ���stack
*
* @author Sandra
* @date 2018/9/24
*/

int main()
{
    int key = 0; // key�������浯����ջ��Ԫ�ص�ֵ
    stack<int> mystack;

    //��Ԫ�ؽ�ջ
    mystack.push(5);
    mystack.push(10);
    mystack.push(15);

    //����ջ��Ԫ�أ������ظ�key
    mystack.pop();
    //cout << "��ǰkey=" << key << endl;

    //����ջ��Ԫ�ص�ֵ
    key = mystack.top();

    mystack.push(20);

    while(!mystack.empty()){
        key = mystack.top();
        mystack.pop();
        cout << "key=" << key << endl;
    }
    return 0;
}
