#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    //vector<struct myString> satistic;
    //myString mys;

    vector<char> satistic; //�洢���ظ��ĳ��ֹ����ַ�
    vector<int> sum; //����������ظ��������Ӵ��ĳ���
    int mylength = 0;
    int maxlength = 0;

    if(s.length() == 1)
    {
        return 1;
    }

    for(unsigned int i=0; i<s.length(); i++)
    {
        cout << s[i] << endl;

        if(satistic.empty())
        {
            //�ַ����黹Ϊ��ʱ
            satistic.push_back(s[i]);
            mylength++;
            if(maxlength < mylength)
            {
                maxlength = mylength;
            }

            cout << mylength << endl;
        }
        else
        {
            if(find(satistic.begin(),satistic.end(),s[i]) == satistic.end())
            {
                //���ַ��ǵ�һ�γ���
                satistic.push_back(s[i]);
                mylength++;
                if(maxlength < mylength)
                {
                    maxlength = mylength;
                }
                //sum.push_back(mylength);

                cout << "���ַ���һ�γ���" << endl;
            }
            else
            {
                //���ַ��Ѿ����ֹ�
                int count = 0;
                vector<char>::iterator it = find(satistic.begin(),satistic.end(),s[i]);

                //����ɾ���ظ�Ԫ�ؼ�֮ǰ��Ԫ�أ�����¼Ԫ�صĸ���
                for(vector<char>::iterator iter = it; iter != satistic.begin(); iter--)
                {
                    count++;
                    satistic.erase(iter);
                }
                satistic.erase(satistic.begin());

                mylength = mylength - count;
                satistic.push_back(s[i]);
                //maxlength = maxlength - count;

                cout << "�ַ��Ѿ����ֹ�" << endl;
            }
        }
    }

    return maxlength;
}

int main()
{
    string s;
    int maxlength;
    cout << "������һ���ַ�" << endl;
    cin >> s;

    maxlength = lengthOfLongestSubstring(s);
    cout << maxlength << endl;
    return 0;
}
