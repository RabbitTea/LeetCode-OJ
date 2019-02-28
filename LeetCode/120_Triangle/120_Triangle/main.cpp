/*
* @description������һ����������ɵ������Σ�ʵ���ǲ�ͬ������һά������ɵĶ�ά���飻����ɶ������ײ�����С·���ͣ�
* @idea��һά��̬�滮��һ��ʼ��˼·�����ɶ�������ÿ�е���Сֵ��Ȼ��Ӻͣ������Ǵ���ģ���Ϊû�п��Ǳ������ڵ�������
        ���ؼ���Ҫ����<����������λ����һ����,б�Խ���Ҳ������>�������Ļ�ÿ��ѡ���ֵ�㲻һ������Сֵ�ˡ�
		˼·��[��������]���еݹ鴦������϶�̬�滮˼��Ļ���������һ��dp���鱣��ÿ�е���С��
		[ע������ÿ��λ�ö���һ���Ӻͣ�ȡ��С��]���������Ա���ݹ飻
* @author��RabbitTea
* @date��2019/2/27
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* ����һ��ʹ��һά����洢�м����������Ҫ���µ��϶�ȡÿһ��ʱ���ø����������0��ʼ��ֵ���ұ�֤��0λ�õ�ֵΪ��С�ͣ�
          ��Ϊ���ڵ�����������ÿ�αȽ�dp[j]��dp[j+1]���ɣ�ѡ��С�ߣ���ʱbp����������һ���������С�ͣ��ټ��ϵ�ǰλ�õ�ֵ��
*/

int minimumTotal(vector<vector<int>>& triangle) {
	int dp[50] = { 0 };

	for (int i = triangle.size() - 1; i >= 0; i--) {  //ע��ӵ�����
		for (int j = 0; j < triangle[i].size(); j++) {
			dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		}
	}

	return dp[0];
}



/*
* ��������ʹ�ö�ά����洢�м�������һƪ���ͽ��ú������https://blog.csdn.net/Jin_Kwok/article/details/51418353
          ��ע��������������������ص�ģ���������������һ�е�����Ϊ���������
*/
/*
int minimumTotal(vector<vector<int>>& triangle) {
	int row = triangle.size();    //row��

	vector<int> rowValue(row,0);    //rowValue������и�ֵ���洢ÿ�еõ����м���
	vector<vector<int>> DP(row, rowValue);   //DPʵ���Ƿ���

	if (row == 0)  return 0;
	if (row == 1)  return triangle[0][0];

	DP[row - 1] = triangle[row - 1];   //�����εײ�һ�е���С��Ϊ�䱾����ʱ����ɴӵ����ڶ��б���

	for (int i = row - 2; i >= 0; i--) {   //�ӵ����ڶ��п�ʼ
		for (int j = 0; j < triangle[i].size(); j++) {
			DP[i][j] = min(DP[i + 1][j], DP[i + 1][j + 1]) + triangle[i][j];
		}
	}

	return DP[0][0];    //��Сֵ
}
*/


/*
* �����˼·��û�п������ڵ�����
int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size() == 0) {
		return 0;
	}

	//��ȡ������
	int m = triangle.size();
	//int n = triangle[0].size();

	int mmin = 0;  //����ÿ�е���Сֵ
	int sum = 0;  //�������·����

	for (int i = 0; i < m; i++) {
		mmin = triangle[i][0];

		for (int j = 0; j < triangle[i].size(); j++) {
			
			//if (min > triangle[i][j]) {
			//	min = triangle[i][j];    //�ҵ�ÿ�е���Сֵ
			//}
			
			mmin = min(mmin, triangle[i][j]);
		}
		sum += mmin;   //�ܺͼ��ϸ��е���Сֵ
	}

	return sum;
}
*/


int main() {
	/*
	* ��ȡ�����˼·�������δ���һά���飬�����Ϊ��ά����
	*/

	int m;    //����
	
	cout << "������������" << endl;
	cin >> m;

	/*
	* ע������triangle(m)ʱ��ϵͳ����ö�ά�����Զ����m�У���ʱ����push_back()����m�к��������У������ǰ�֮ǰ��ֵ���ǵ�
	*/
	vector<vector<int>> triangle(m);

	/*
	* �Ƚϼ������뷽ʽ
	*/
	cout << "�������ݣ� " << endl;
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
	* �ȽϷ��������뷽ʽ
	for (int i = 0; i < m; i++) {
		int n;   //ÿ������(���ܲ�ͬ)
		cout << "�������" << i + 1 << "�е�������" << endl;
		cin >> n;

		vector<int> row;    //����һά���飬���ﲻ��Ҫ������С����������ֵʱ����push_back()

		int num;
		cout << "������������е���ֵ��" << endl;

		for (int j = 0; j < n; j++) {
			cin >> num;
			row.push_back(num);
		}

		triangle[i] = row;    //���ڶ�̬�����Ѿ���ʼ������ÿ�и��˳�ֵ��������Խ�һά����ֱ�Ӹ�����ά�����һ��
	}
	*/

	/*
	* ��������
	for (int i = 0; i < m; i++) {
		//cout << "i'm here" << endl;
		for (int j = 0; j < triangle[i].size(); j++) {
			//cout << "�ڶ���ѭ��" << endl;
			cout << triangle[i][j] << " ";
		}
		cout << endl;
	}
	*/

    int sum = minimumTotal(triangle);

	cout << "���·����Ϊ��" << sum <<endl;
}