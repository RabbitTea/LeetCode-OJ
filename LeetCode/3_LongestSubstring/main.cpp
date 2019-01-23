#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    //vector<struct myString> satistic;
    //myString mys;

    vector<char> satistic; //存储无重复的出现过的字符
    vector<int> sum; //保存各个无重复的连续子串的长度
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
            //字符数组还为空时
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
                //该字符是第一次出现
                satistic.push_back(s[i]);
                mylength++;
                if(maxlength < mylength)
                {
                    maxlength = mylength;
                }
                //sum.push_back(mylength);

                cout << "该字符第一次出现" << endl;
            }
            else
            {
                //该字符已经出现过
                int count = 0;
                vector<char>::iterator it = find(satistic.begin(),satistic.end(),s[i]);

                //倒序删除重复元素及之前的元素，并记录元素的个数
                for(vector<char>::iterator iter = it; iter != satistic.begin(); iter--)
                {
                    count++;
                    satistic.erase(iter);
                }
                satistic.erase(satistic.begin());

                mylength = mylength - count;
                satistic.push_back(s[i]);
                //maxlength = maxlength - count;

                cout << "字符已经出现过" << endl;
            }
        }
    }

    return maxlength;
}

int main()
{
    string s;
    int maxlength;
    cout << "请输入一串字符" << endl;
    cin >> s;

    maxlength = lengthOfLongestSubstring(s);
    cout << maxlength << endl;
    return 0;
}
