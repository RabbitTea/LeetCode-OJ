/*
* @Description：给定一个正整数数组，判断其是否分为两个和相同的子数组；
* @idea：0-1背包问题，可以用动态规划思想来处理大数据的情况。
         这里数组元素的和一定为偶数，否则不能分成两个子数组。

		 定义一个一维的布尔类型的dp数组，其中dp[i]表示原数组是否可以取出若干个数字，其和为i；
		 数组元素和的一半为我们的目标(target)，最后只需要返回dp[target]的结果即可。
		 初始化dp[0]为true，找出状态转移方程为：
		 dp[j] = dp[j] || dp[j-nums[i]]  （nums[i] <= j <= target）
*/

#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
	int sum = accumulate(nums.begin(), nums.end(), 0);   //STL的accumulate函数求数组的和(加上0)
	int target = sum >> 1;   //理解为sum/2

	if (sum & 1) return false;    //这里一定是&符号

	vector<bool> dp(target + 1, false);   //dp数组大小为target+1，初始化为false
	dp[0] = true;

	for (int num : nums) {
		for (int i = target; i >= num; --i) {
			dp[i] = dp[i] || dp[i - num];
		}
	}
	return dp[target];
}

int main() {
	vector<int> nums;
	int num;

	cout << "请输入正整数数组：" << endl;
	while (cin >> num) {
		nums.push_back(num);
	}

	bool res = canPartition(nums);

	if (res == true) {
		cout << "结果为true" << endl;
	}
	else {
		cout << "结果为false" << endl;
	}
	
}