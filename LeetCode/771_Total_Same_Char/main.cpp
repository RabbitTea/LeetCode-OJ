/**
* @description:����һ���ַ���J��һ���ַ���S������S�н�J����ͬ�ַ��ĸ�������Сд���У�
* @idea: ͨ��STL��׼���е�Map�������Լ�ֵ�ԵĴ洢��ʽ�ֱ�洢S��J�е��ַ����������
         ���J�а���ĳ���ַ������ȡS�ж�Ӧ�ַ��ĸ��������ܸ�����ӡ�
* @author: SA18225018
* @date: 2018/10/17
**/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int totalSameChar(char J[], char S[], int nj, int ns)
{
    map<char,int> hashmapJ; // �����ַ�����J��map����
    map<char,int> hashmapS; // �����ַ�����S��map����
    int countchar = 0; // ��ʼ����ͬ���ܸ���Ϊ0

    /*��J�е�Ԫ�ر��浽mapԪ�أ���Ϊ�ַ���ֵΪ��Ӧ����*/
    for(int i=0;i<nj;i++){
        char tmp = J[i];
        if(hashmapJ.find(tmp) != hashmapJ.end())
            hashmapJ[tmp]++;
        else
            hashmapJ.insert(pair<char,int>(tmp,1));
    }

    /*��S�е�Ԫ�ر��浽mapԪ�أ���Ϊ�ַ���ֵΪ��Ӧ����*/
    for(int j=0;j<ns;j++){
        char tmp = S[j];
        if(hashmapS.find(tmp) != hashmapS.end())
            hashmapS[tmp]++;
        else
            hashmapS.insert(pair<char,int>(tmp,1));
    }

    map<char,int>::iterator iter; //��������������Ա���hashmapS
    iter = hashmapS.begin();
    while(iter != hashmapS.end()){
        char tmp = iter->first; // tmp����mapS�еļ���iter->first��
        if(hashmapJ.find(tmp) != hashmapJ.end())
            countchar = countchar + iter->second; // ���J������ͬ��Ԫ�أ���ʹcountchar��ֵ����mapS�ж�Ӧ�ַ��ĸ�����ֵ��iter->second��
        iter++;
    }

    return countchar;
}

int main()
{
    int nj, ns;
    cout << "�������ַ���J���ַ�������" << endl;
    cin >> nj;

    char J[nj];
    cout << "�������ַ���J��" << endl;
    cin >> J;

    cout << "�������ַ���S���ַ�������" << endl;
    cin >> ns;

    char S[ns];
    cout << "�������ַ���S��" << endl;
    cin >> S;

    int totalcount = 0;
    totalcount = totalSameChar(J,S,nj,ns);
    cout << "��ͬ�ַ��ĸ���Ϊ��" << totalcount << endl;
    return 0;
}
