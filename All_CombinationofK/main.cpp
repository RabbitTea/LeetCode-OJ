/**
* @description: Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
                [给定整数范围的区间为[1,n]，且给出子数组元素的个数k，输出[1,n]之间所有含k个元素的子数组]
* @idea: 选择最简单的方法——嵌套循环，依次遍历；且注意输出格式
* @author: SA18225018
* @date: 2018/10/17
**/
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cout << "请输入整数的最大值n：" << endl;
    cin >> n;

    cout << "请输入子数组的范围k：" << endl;
    cin >> k;

    for(int i=1;i<=n;i++){ // i负责确定第一个元素值
        int p = i;  // p用来保存i值，因为在下一层循环时需要将p后移；
        for(int j=p+1;j<=n;j++,p++){ // j负责确定第二个元素值
            cout << '[' << i << ',';
            for(int q=j;q<p+k-1;q++){ // p负责输出后边第2到第k的值
                cout << q << ',';
            }
            cout << p+k-1 << ']' << endl;
        }
    }
    return 0;
}
