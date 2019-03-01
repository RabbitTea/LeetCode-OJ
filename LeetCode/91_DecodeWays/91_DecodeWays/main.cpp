/*
* @description：A-Z分别编码为1-26，给定一个数字，输出其可由字母构成的所有方式；如12的结果为2[分为AB(1 2)和L(12)]；
* @idea：动态规划思想；状态转移方程为f(n)=f(n-1)+f(n-2)，f(n)指到该数字处所有的构造方式数，使用一维数组dp[]存储；
* @author：RabbitTea
* @date：2019/3/1
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDecodings(string s) {
	int len = s.length();
	vector<int> dp(len);   //中间结果数组

	if (len == 1) return 1;
	dp[0] = 1;

	/*
	* 测试数字字符转化为数字
	if (len == 2) {
		char c1 = s.at(0);
		int num1 = c1-48;
		char c2 = s.at(1);
		int num2 = c2-48;
		int num = num1+num2;
		cout << "num1=" << num1 << endl;
		cout << "第0个字符" << s.at(0) << endl;
		cout << "num=" << num << endl;
			if (num >= 1 && num <= 26) {
				return 2;
			}
	}
	*/

	for (int i = 1; i < s.length(); i++) {
		int doubleNum = (s.at(i)-48) + 10 * (s.at(i - 1)-48);
		int temp1 = (i == 0) ? 1 : dp[i - 1];

		if (doubleNum >= 1 && doubleNum <= 26) {
			int temp2 = (i - 1 == 0) ? 1 : dp[i - 2];

			dp[i] = temp1 + temp2;
		}
		else {
			dp[i] = temp1;
		}
	}

	return dp[len - 1];
}

/*
* 网上同样的思想，但编程逻辑更简单 
int numDecodings(string s) {
	int len = s.size();     //s.size()和s.length()得到的数值应该不一样

	if (s.empty())  return 0;
	if (s[0] == '0') return 0;

	vector<int> dp(len + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < len + 1; i++) {
		if (s[i - 1] != '0')  dp[i] += dp[i - 1];
		if (s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10") dp[i] += dp[i - 2];
	}

	return dp[len];
}
*/


int main() {
	string s;
	cout << "请输入数字字符串：" << endl;
	cin >> s;

	cout << s.length() << endl;

	int res = numDecodings(s);
	cout << "编码总数为：" << res << endl;
}