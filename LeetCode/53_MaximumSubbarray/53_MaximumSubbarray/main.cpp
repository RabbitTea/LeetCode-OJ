/*
* @description：最大连续子数组的和；给定一个数组，找出连续的一个子数组，其和为所有连续子数组的最大值；
* @idea：一维动态规划题目，n个数可以分为n个子问题；可用一维整型数组保存1-n的前n个数各自和的值；
         △注意这里一维数组保存的值：如果前边的和为负，即第i-1个元素的值为负/零，则当前i位置的和为其本身；若为正，则其值为前边和与当前值相加；
		   要初始化一个最大值，每次循环得到的和与最大值比较，必要时进行更新；
		 这里有一个简单点是不需要输出最大连续子数组的值；
* @author：RabbitTea
* @date：2019/2/27
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
	/*
	vector<int> sums;  //保存子连续字符串的和

	if (nums.size() > 0) {
		
		//注意这里必须用push_back方法添加值，而不能用索引，因为是vector数组，这个时候该索引下还没有值，会发生vector越界错误；
		
		sums.push_back(nums[0]);  //第一个数的和为自身的值
	}
   
	int sum = nums[0];

	for (int i = 1; i < nums.size(); i++) {

		if (sums[i - 1] + i > 0)   //当加上第i个值后和变大时，和更新为加上i之后的值
			sums.push_back(sums[i - 1] + nums[i]);
		else                          
			sums.push_back(i);                //若变小，则前面的和清0，从该i值开始计数
		
		sum = max(sum, sums[i]);
	}

	
	return sum;
	*/

	if (nums.size() <= 0)   //传入数组参数时必要的判断条件
		return 0;

	int sum = 0;  //不用数组来保存每一组的结果，而是设置一个int类型的值，不断用以更新max值
	int max = nums[0];

	for (int i = 0; i < nums.size(); i++) {
		if (sum < 0) {    //如果之前和为负，则第i处的和一定比nums[i]要小，此时更新sum[i]为nums[i]
			sum = nums[i];
		}
		else {
			sum += nums[i];
		}
		max = (sum > max) ? sum : max;    //更新当前得到的和与之前最大和的最大值
	}

	return max;
}

int main() {
	vector<int> nums;
	cout << "请输入数组的值：" << endl;

	/*
	* C++ 控制台输入一串整型vector数组
	*/
	int num;   //用于获取单个数字
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	int sum = maxSubArray(nums);
	cout << "最大连续子数组的和为：" << sum << endl;
}