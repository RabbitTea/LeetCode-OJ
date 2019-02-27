/*
* @description���������������ĺͣ�����һ�����飬�ҳ�������һ�������飬���Ϊ������������������ֵ��
* @idea��һά��̬�滮��Ŀ��n�������Է�Ϊn�������⣻����һά�������鱣��1-n��ǰn�������Ժ͵�ֵ��
         ��ע������һά���鱣���ֵ�����ǰ�ߵĺ�Ϊ��������i-1��Ԫ�ص�ֵΪ��/�㣬��ǰiλ�õĺ�Ϊ�䱾����Ϊ��������ֵΪǰ�ߺ��뵱ǰֵ��ӣ�
		   Ҫ��ʼ��һ�����ֵ��ÿ��ѭ���õ��ĺ������ֵ�Ƚϣ���Ҫʱ���и��£�
		 ������һ���򵥵��ǲ���Ҫ�����������������ֵ��
* @author��RabbitTea
* @date��2019/2/27
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
	/*
	vector<int> sums;  //�����������ַ����ĺ�

	if (nums.size() > 0) {
		
		//ע�����������push_back�������ֵ������������������Ϊ��vector���飬���ʱ��������»�û��ֵ���ᷢ��vectorԽ�����
		
		sums.push_back(nums[0]);  //��һ�����ĺ�Ϊ�����ֵ
	}
   
	int sum = nums[0];

	for (int i = 1; i < nums.size(); i++) {

		if (sums[i - 1] + i > 0)   //�����ϵ�i��ֵ��ͱ��ʱ���͸���Ϊ����i֮���ֵ
			sums.push_back(sums[i - 1] + nums[i]);
		else                          
			sums.push_back(i);                //����С����ǰ��ĺ���0���Ӹ�iֵ��ʼ����
		
		sum = max(sum, sums[i]);
	}

	
	return sum;
	*/

	if (nums.size() <= 0)   //�����������ʱ��Ҫ���ж�����
		return 0;

	int sum = 0;  //��������������ÿһ��Ľ������������һ��int���͵�ֵ���������Ը���maxֵ
	int max = nums[0];

	for (int i = 0; i < nums.size(); i++) {
		if (sum < 0) {    //���֮ǰ��Ϊ�������i���ĺ�һ����nums[i]ҪС����ʱ����sum[i]Ϊnums[i]
			sum = nums[i];
		}
		else {
			sum += nums[i];
		}
		max = (sum > max) ? sum : max;    //���µ�ǰ�õ��ĺ���֮ǰ���͵����ֵ
	}

	return max;
}

int main() {
	vector<int> nums;
	cout << "�����������ֵ��" << endl;

	/*
	* C++ ����̨����һ������vector����
	*/
	int num;   //���ڻ�ȡ��������
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	int sum = maxSubArray(nums);
	cout << "�������������ĺ�Ϊ��" << sum << endl;
}