/**
* @description:给定一个字符串J和一个字符串S，计算S中较J中相同字符的个数（大小写敏感）
* @idea: 通过STL标准库中的Map容器，以键值对的存储方式分别存储S和J中的字符及其个数；
         如果J中包含某个字符，则获取S中对应字符的个数，将总个数相加。
* @author: SA18225018
* @date: 2018/10/17
**/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int totalSameChar(char J[], char S[], int nj, int ns)
{
    map<char,int> hashmapJ; // 定义字符数组J的map容器
    map<char,int> hashmapS; // 定义字符数组S的map容器
    int countchar = 0; // 初始化相同的总个数为0

    /*将J中的元素保存到map元素，键为字符，值为对应个数*/
    for(int i=0;i<nj;i++){
        char tmp = J[i];
        if(hashmapJ.find(tmp) != hashmapJ.end())
            hashmapJ[tmp]++;
        else
            hashmapJ.insert(pair<char,int>(tmp,1));
    }

    /*将S中的元素保存到map元素，键为字符，值为对应个数*/
    for(int j=0;j<ns;j++){
        char tmp = S[j];
        if(hashmapS.find(tmp) != hashmapS.end())
            hashmapS[tmp]++;
        else
            hashmapS.insert(pair<char,int>(tmp,1));
    }

    map<char,int>::iterator iter; //定义迭代器，用以遍历hashmapS
    iter = hashmapS.begin();
    while(iter != hashmapS.end()){
        char tmp = iter->first; // tmp保存mapS中的键（iter->first）
        if(hashmapJ.find(tmp) != hashmapJ.end())
            countchar = countchar + iter->second; // 如果J中有相同的元素，则使countchar的值加上mapS中对应字符的个数。值（iter->second）
        iter++;
    }

    return countchar;
}

int main()
{
    int nj, ns;
    cout << "请输入字符串J的字符个数：" << endl;
    cin >> nj;

    char J[nj];
    cout << "请输入字符串J：" << endl;
    cin >> J;

    cout << "请输入字符串S的字符个数：" << endl;
    cin >> ns;

    char S[ns];
    cout << "请输入字符串S：" << endl;
    cin >> S;

    int totalcount = 0;
    totalcount = totalSameChar(J,S,nj,ns);
    cout << "相同字符的个数为：" << totalcount << endl;
    return 0;
}
