/*
* @description：给定一个由数字组成的三角形，实际是不同列数的一维数组组成的二维数组；输出由顶部到底部的最小路径和；
* @idea：一维动态规划；一开始的思路会想由顶向下找每行的最小值，然后加和；但这是错误的，因为没有考虑必须相邻的条件；
        △关键是要考虑<必须走相邻位置这一条件,斜对角线也算相邻>，这样的话每行选择的值便不一定是最小值了。
		思路：[从下往上]进行递归处理，而结合动态规划思想的话，可以用一个dp数组保存每行的最小和
		[注意这里每个位置都有一个加和，取最小者]，这样可以避免递归；
* @author：RabbitTea
* @date：2019/2/27
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 方法一：使用一维数组存储中间结果，这就需要由下到上读取每一行时重置该数组从索引0开始的值，且保证第0位置的值为最小和；
          因为相邻的限制条件，每次比较dp[j]和dp[j+1]即可，选最小者；此时bp的内容是下一层的依次最小和，再加上当前位置的值。
*/

int minimumTotal(vector<vector<int>>& triangle) {
	int dp[50] = { 0 };

	for (int i = triangle.size() - 1; i >= 0; i--) {  //注意从底向下
		for (int j = 0; j < triangle[i].size(); j++) {
			dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		}
	}

	return dp[0];
}



/*
* 方法二：使用二维数组存储中间结果；有一篇博客讲得很清楚：https://blog.csdn.net/Jin_Kwok/article/details/51418353
          △注意这里给定的三角是有特点的，其最大列数即最后一行的列数为矩阵的行数
*/
/*
int minimumTotal(vector<vector<int>>& triangle) {
	int row = triangle.size();    //row行

	vector<int> rowValue(row,0);    //rowValue按最大列赋值，存储每行得到的中间结果
	vector<vector<int>> DP(row, rowValue);   //DP实际是方阵

	if (row == 0)  return 0;
	if (row == 1)  return triangle[0][0];

	DP[row - 1] = triangle[row - 1];   //三角形底部一行的最小和为其本身；此时下面可从倒数第二行遍历

	for (int i = row - 2; i >= 0; i--) {   //从倒数第二行开始
		for (int j = 0; j < triangle[i].size(); j++) {
			DP[i][j] = min(DP[i + 1][j], DP[i + 1][j + 1]) + triangle[i][j];
		}
	}

	return DP[0][0];    //最小值
}
*/


/*
* 错误的思路，没有考虑相邻的条件
int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size() == 0) {
		return 0;
	}

	//获取行列数
	int m = triangle.size();
	//int n = triangle[0].size();

	int mmin = 0;  //保存每行的最小值
	int sum = 0;  //保存最短路径和

	for (int i = 0; i < m; i++) {
		mmin = triangle[i][0];

		for (int j = 0; j < triangle[i].size(); j++) {
			
			//if (min > triangle[i][j]) {
			//	min = triangle[i][j];    //找到每行的最小值
			//}
			
			mmin = min(mmin, triangle[i][j]);
		}
		sum += mmin;   //总和加上该行的最小值
	}

	return sum;
}
*/


int main() {
	/*
	* 获取输入的思路：先依次创建一维数组，再组合为二维数组
	*/

	int m;    //行数
	
	cout << "请输入行数：" << endl;
	cin >> m;

	/*
	* 注意这里triangle(m)时，系统会给该二维数组自动添加m行，这时再用push_back()会在m行后接着添加行，而不是把之前的值覆盖掉
	*/
	vector<vector<int>> triangle(m);

	/*
	* 比较简洁的输入方式
	*/
	cout << "输入数据： " << endl;
	for (int i = 0; i < m; i++) {
		int num;
		while (cin >> num){
			triangle[i].push_back(num);
			if (cin.get() == '\n'){
				break;
			}
		}
	}


	/*
	* 比较繁琐的输入方式
	for (int i = 0; i < m; i++) {
		int n;   //每行列数(可能不同)
		cout << "请输入第" << i + 1 << "行的列数：" << endl;
		cin >> n;

		vector<int> row;    //创建一维数组，这里不需要声明大小，则后面添加值时可用push_back()

		int num;
		cout << "请依次输入该行的数值：" << endl;

		for (int j = 0; j < n; j++) {
			cin >> num;
			row.push_back(num);
		}

		triangle[i] = row;    //用于动态数组已经初始化过，每行赋了初值，这里可以将一维数组直接赋给二维数组的一行
	}
	*/

	/*
	* 测试输入
	for (int i = 0; i < m; i++) {
		//cout << "i'm here" << endl;
		for (int j = 0; j < triangle[i].size(); j++) {
			//cout << "第二层循环" << endl;
			cout << triangle[i][j] << " ";
		}
		cout << endl;
	}
	*/

    int sum = minimumTotal(triangle);

	cout << "最短路径和为：" << sum <<endl;
}