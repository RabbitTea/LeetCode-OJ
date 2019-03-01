/*
* @description������һ���ַ��������������Ӵ���
* @idea�����Ƕ�άDP���⣬��ν�Ķ�ά����ָ��Ҫһ����ά��dp[][]���飬���к�ΪҪ�����ֵ���ڵ���������Ӧ��Ԫ��ֵΪԼ��������õ�ֵ��
         �������⣺�����������һ�����Ĵ�������������Ĵ����ȣ������һ��һά�����ݴ漴�ɣ���������Ҫ����Ӵ���ʲô��
		 ��ô����Ҫ�Ӵ��Ŀ�ͷλ�úͽ���λ�ã�������Ҫ��ά����ά����Ϣ��
* @author��RabbitTea
* @date��2019/3/1
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�ж�һ���ַ����Ƿ�Ϊ���Ĵ�
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
* �Լ�д�ķ����������������
string longestPalindrome(string s) {
	int len = s.length();   //�ַ�������

	vector<vector<int>> dp(len, vector<int>(len));   //��ά�����ݴ��м���

	int max_res = 0;
	int max_i = 0;
	int max_j = 0;

	//dp[][]�����ʼ�������Խ��߼�����Ԫ�ؾ�Ϊ0��
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (i >= j) {
				dp[i][j] = 0;
			}
			else {
				//�ж��Ӵ��Ƿ�Ϊ���Ĵ�
				bool isPal = isPalindrome(s.substr(i, j - i + 1));
				if (isPal) {
					dp[i][j] = j - i + 1;
					if (max_res < dp[i][j]) {   //�������ֵ������
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
* ���䷽��֮һ����������ɢ��������ʱ��Ҫ�����ַ���Ŀ�϶����4���ַ������3����϶��
*/
string longestPalindrome1(string s) {
	if (s.length() < 2) {
		return s;
	}

	int length = 0;			// �����Ӵ��ĳ���
	string MaxPali = "";	// ������Ӵ�
	int n = s.length();
	for (int i = 0; i < 2 * n - 1; i++) {	// �Գ��������Ϊ2*s.length()-1(Ԫ�صĸ�����Ԫ�صļ�϶��
		int left = i / 2 - 1;	// �Գ������ߵ�Ԫ�ص��±�
		if (i % 2) {			// �Գ���Ϊ��϶ʱ
			left++;
		}
		int right = left + 1;
		if (i % 2 == 0) {		// �Գ���ΪԪ��ʱ
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
		string pali = s.substr(left + 1, right - left - 1);	// ��i���Գ����Ӧ��������Ӵ�
		if (length < pali.length()) {
			length = pali.length();
			MaxPali = pali;
		}
	}
	return MaxPali;
}


int main() {
	string s;
	cout << "�������ַ�����" << endl;
	cin >> s;

	string res = longestPalindrome(s);

	cout << "����Ĵ��ǣ�" << res << endl;
}