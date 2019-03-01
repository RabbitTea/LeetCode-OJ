/*
* @description：给定一个字符串，输出最长回文子串；
* @idea：这是二维DP问题，所谓的二维，是指需要一个二维的dp[][]数组，行列号为要输出的值所在的索引，对应的元素值为约束条件求得的值；
         适用问题：比如这里给定一个回文串，如果输出最长回文串长度，则仅需一个一维数组暂存即可，但这里需要输出子串是什么，
		 那么就需要子串的开头位置和结束位置，所以需要二维数组维护信息。
* @author：RabbitTea
* @date：2019/3/1
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//判断一个字符串是否为回文串
bool isPalindrome(string s) {
	int i = 0;
	int j = s.length() - 1;

	while (i < j) {
		if (s[i] == s[j]) {
			i++;
			j--;
		}
		else {
			return false;
		}
	}

	return true;
}

/*
* 自己写的方法，这个方法巨慢
string longestPalindrome(string s) {
	int len = s.length();   //字符串长度

	vector<vector<int>> dp(len, vector<int>(len));   //二维数组暂存中间结果

	int max_res = 0;
	int max_i = 0;
	int max_j = 0;

	//dp[][]数组初始化；主对角线及以下元素均为0；
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (i >= j) {
				dp[i][j] = 0;
			}
			else {
				//判断子串是否为回文串
				bool isPal = isPalindrome(s.substr(i, j - i + 1));
				if (isPal) {
					dp[i][j] = j - i + 1;
					if (max_res < dp[i][j]) {   //更新最大值及索引
						max_res = dp[i][j];
						max_i = i;
						max_j = j;
					}
				}
				else
					dp[i][j] = 0;
			}
		}
	}

	string res = s.substr(max_i, max_j - max_i + 1);
	return res;
}
*/


/*
* 经典方法之一：中心轴扩散法；遍历时需要考虑字符间的空隙，如4个字符需添加3个空隙。
*/
string longestPalindrome1(string s) {
	if (s.length() < 2) {
		return s;
	}

	int length = 0;			// 回文子串的长度
	string MaxPali = "";	// 最长回文子串
	int n = s.length();
	for (int i = 0; i < 2 * n - 1; i++) {	// 对称轴的数量为2*s.length()-1(元素的个数和元素的间隙）
		int left = i / 2 - 1;	// 对称轴两边的元素的下标
		if (i % 2) {			// 对称轴为间隙时
			left++;
		}
		int right = left + 1;
		if (i % 2 == 0) {		// 对称轴为元素时
			right++;
		}

		while (left >= 0 && right < n) {
			if (s[left] == s[right]) {
				left--;
				right++;
			}
			else {
				break;
			}
		}
		string pali = s.substr(left + 1, right - left - 1);	// 第i个对称轴对应的最长回文子串
		if (length < pali.length()) {
			length = pali.length();
			MaxPali = pali;
		}
	}
	return MaxPali;
}


int main() {
	string s;
	cout << "请输入字符串：" << endl;
	cin >> s;

	string res = longestPalindrome(s);

	cout << "最长回文串是：" << res << endl;
}