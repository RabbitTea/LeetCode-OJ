/*
* @description������һ������(��)���ַ������ҳ����������Ч�����Ӵ�������䳤�ȣ�
* @idea��1.��̬�滮�Ĺؼ��Ǹ���Լ�������������״̬ת�Ʒ��̣�Ȼ����ݷ����ɵ����ϱ�̣�
         2.�ö�ջʵ�֣�
* @author��RabbitTea
* @date��2019/2/28
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


/*
* ����һ����̬�滮������ʹ��һάdp���鱣�������ÿһ���ַ���ʱ�������Ӵ��ĵ�ǰ���Ϸ����ȣ�ÿ�������ֵ�Ƚϣ��������ֵ��
*/
/*
int longestValidParentheses(string s) {
	int len = s.length();
	int maxRes = 0;

	vector<int> dp;
	dp.push_back(0);    //���ܵ�һ��Ԫ����(����)�����Ⱦ�Ϊ0

	for (int i = 1; i < len; i++) {   //�ӵڶ���λ�ÿ�ʼ�����ַ���
		if (s.at(i) == '(') {  //�����ų��ȼ�Ϊ0
			dp.push_back(0);
		}

		if (s.at(i) == ')') {  //��������Ҫ�ж�ǰһ���ַ���'('����')'
			if (s.at(i - 1) == '(') {   //�ɶԵ����ţ���ԭ���Ļ����ϼ�2
				dp.push_back((i > 2 ? dp[i - 2] : 0) + 2);
			}
			else if (i >= dp[i - 1] + 1 && s.at(i - dp[i - 1] - 1) == '(') {   //ǰ��˵�����жԳ�λ�ã�����˵����Գ�λ�ô�Ԫ��Ϊ'('����ԭ�������ϸ���dpֵ
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
* ����������ջ���ԣ���ʱ���ǽ�������ջ�����ǽ�������(�����Ų�ѹ���ջ)��Ӧ���±���ջ����ͨ��һ��������¼��Ч���ŵ���ʼλ�ã���������ֱ�Ӷ�ջ��Ԫ�ؽ��м��㣻
          �ò��ͽ��ú���ϸ��https://blog.csdn.net/yuanliang861/article/details/84847024
*/

int longestValidParentheses(string s) {
	int maxRes = 0;
	int start = -1;  //��Ч���ŵ���ʼλ��

	stack<int> temp;  //ʹ��STL�еĶ�ջ

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {  //�����Ž�ջ
			temp.push(i);     //ע�������������ŵ��±���ջ
		}
		else {   //�����Ų���ջ����Ϊ�������
			if (!temp.empty()) {   //ջ��Ϊ����˵����Գɹ�
				temp.pop();
				if (temp.empty()) {  //����ջ��ջΪ�գ�����Ч����ֹ
					maxRes = max(maxRes, i-start);
				}
				else {
					maxRes = max(maxRes, i - temp.top());  //ջ�����±�ֵ
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
	cout << "�����������ַ�����" << endl;
	cin >> s;

	int maxRes = longestValidParentheses(s);

	cout << "���Ч�����Ӵ��ĳ���Ϊ��" << maxRes << endl;
}