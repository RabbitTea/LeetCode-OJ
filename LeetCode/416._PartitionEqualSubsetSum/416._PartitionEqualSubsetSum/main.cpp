/*
* @Description������һ�����������飬�ж����Ƿ��Ϊ��������ͬ�������飻
* @idea��0-1�������⣬�����ö�̬�滮˼������������ݵ������
         ��������Ԫ�صĺ�һ��Ϊż���������ֳܷ����������顣

		 ����һ��һά�Ĳ������͵�dp���飬����dp[i]��ʾԭ�����Ƿ����ȡ�����ɸ����֣����Ϊi��
		 ����Ԫ�غ͵�һ��Ϊ���ǵ�Ŀ��(target)�����ֻ��Ҫ����dp[target]�Ľ�����ɡ�
		 ��ʼ��dp[0]Ϊtrue���ҳ�״̬ת�Ʒ���Ϊ��
		 dp[j] = dp[j] || dp[j-nums[i]]  ��nums[i] <= j <= target��
*/

#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
	int sum = accumulate(nums.begin(), nums.end(), 0);   //STL��accumulate����������ĺ�(����0)
	int target = sum >> 1;   //���Ϊsum/2

	if (sum & 1) return false;    //����һ����&����

	vector<bool> dp(target + 1, false);   //dp�����СΪtarget+1����ʼ��Ϊfalse
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

	cout << "���������������飺" << endl;
	while (cin >> num) {
		nums.push_back(num);
	}

	bool res = canPartition(nums);

	if (res == true) {
		cout << "���Ϊtrue" << endl;
	}
	else {
		cout << "���Ϊfalse" << endl;
	}
	
}