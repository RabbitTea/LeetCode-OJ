/*
* @description：给定一个仅含(和)的字符串，找出最长连续的有效括号子串，输出其长度；
* @idea：1.动态规划的关键是根据约束条件，抽象出状态转移方程，然后根据方程由底向上编程；
         2.用堆栈实现；
* @author：RabbitTea
* @date：2019/2/28
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


/*
* 方法一：动态规划方法；使用一维dp数组保存遍历到每一个字符处时，所在子串的当前最大合法长度，每次与最大值比较，更新最大值；
*/
/*
int longestValidParentheses(string s) {
	int len = s.length();
	int maxRes = 0;

	vector<int> dp;
	dp.push_back(0);    //不管第一个元素是(还是)，长度均为0

	for (int i = 1; i < len; i++) {   //从第二个位置开始遍历字符串
		if (s.at(i) == '(') {  //左括号长度记为0
			dp.push_back(0);
		}

		if (s.at(i) == ')') {  //右括号需要判断前一个字符是'('还是')'
			if (s.at(i - 1) == '(') {   //成对的括号，在原来的基础上加2
				dp.push_back((i > 2 ? dp[i - 2] : 0) + 2);
			}
			else if (i >= dp[i - 1] + 1 && s.at(i - dp[i - 1] - 1) == '(') {   //前者说明其有对称位置，后者说明其对称位置处元素为'('，在原来基础上更新dp值
				dp.push_back(dp[i - 1] + ((i > dp[i - 1] + 2) ? dp[i - dp[i - 1] - 2] : 0) + 2);
			}
			else
				dp.push_back(0);
			maxRes = max(maxRes, dp[i]);
		}
	}

	return maxRes;
}
*/


/*
* 方法二：堆栈特性；此时不是将符号入栈，而是将左括号(右括号不压入堆栈)对应的下标入栈，且通过一个变量记录有效括号的起始位置，这样可以直接对栈内元素进行计算；
          该博客讲得很详细：https://blog.csdn.net/yuanliang861/article/details/84847024
*/

int longestValidParentheses(string s) {
	int maxRes = 0;
	int start = -1;  //有效括号的起始位置

	stack<int> temp;  //使用STL中的堆栈

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {  //左括号进栈
			temp.push(i);     //注意这里是左括号的下标入栈
		}
		else {   //右括号不进栈，分为两种情况
			if (!temp.empty()) {   //栈不为空则说明配对成功
				temp.pop();
				if (temp.empty()) {  //若出栈后栈为空，则有效串截止
					maxRes = max(maxRes, i-start);
				}
				else {
					maxRes = max(maxRes, i - temp.top());  //栈顶的下标值
				}
			}
			else {
				start = i;     
			}
		}
	}

	return maxRes;
}



int main() {
	string s;
	cout << "请输入括号字符串：" << endl;
	cin >> s;

	int maxRes = longestValidParentheses(s);

	cout << "最长有效括号子串的长度为：" << maxRes << endl;
}