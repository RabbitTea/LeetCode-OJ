/*
* @description：爬楼梯；给定n个台阶，一次只能走1步或2步，输出有几种走到终点的方式；
* @idea： 一维动态规划题目；所谓一维，即指保存子问题的结果所用的数据结构的类型；该问题类似斐波那契数列；
          第n个台阶的方式数由第n-1问题加1和第n-2问题加2所得，可以得到数学表达式：f(n)=f(n-1)+f(n-2)；
		  那么考虑，由一个n+1大小的一维数组可以保存1-n层台阶的结果。
* @author：RabbitTea
* @date：2019/2/27
*/

#include <iostream>
#include <vector>

using namespace std;

int climbWays(int n) {
	//int *ways = new int[n+1];  //DP思想，保存子问题的结果
	//int ways[n + 1] = { 0 };
	vector<int> ways(n + 1);
	
	//1层台阶有一种走法，2层台阶有两种走法，保存到数组中
	ways[0] = 1;
	ways[1] = 2;
	
	for (int i = 2; i < n; i++) {
		ways[i] = ways[i - 1] + ways[i - 2];
	}
	
	return ways[n - 1];
}

int main() {
	int n;
	cout << "请输入台阶数：" << endl;
	cin >> n;

	int count = climbWays(n);
	cout << "共有" << count << "种方式；" << endl;
}