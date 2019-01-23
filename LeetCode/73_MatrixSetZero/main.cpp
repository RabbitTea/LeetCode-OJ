/**
* @description: ����һ��m��n �������ĳ��Ԫ��Ϊ0�����������к��ж�����Ϊ0
* @idea: ʹ�ú㶨��O(1)�Ŀռ临�Ӷȡ���ԭ�ر���Ҫ��0���к��У�
         ѡ���һ�е�Ԫ�ر����Ӧ�����Ƿ�Ҫ��0��ѡ���һ�е�Ԫ�ر����Ӧ�����Ƿ�Ҫ��0��
         ����������־λ���ֱ��ʾ��һ�к͵�һ���Ƿ�Ҫ��0��
         ��ɨ�赽��һ�к͵�һ���е�Ԫ�أ��ж����������е�Ԫ���Ƿ�Ҫ��0�������ͨ����־λ�ж��Ƿ����һ�к͵�һ����0��
         ���ؼ��������������У���ͨ����־λ�ñ�����к��С�
* @author: SA18225018
* @date: 2018/10/24
**/
#include <iostream>
#include <vector>

using namespace std;

void setMatrixZero(vector<vector<int> > &matrix,int m, int n){
    //ע��һ��Ҫ��matrix�����ã��������˳�����Ķ�ά����ֵ����ı�
    bool firstRow = false; // �б�־λ����ʼΪfalse�����ɨ�赽ÿһ�еĿ�ͷԪ��Ϊ0������Ϊtrue��������Ϊfalse
    bool firstCol = false; // �б�־λ����ʼΪfalse�����ɨ�赽ÿһ�еĿ�ͷԪ��Ϊ0������Ϊtrue��������Ϊfalse

    //ͳ��Ҫ��0���к��У������õ�һ�к͵�һ�еı�־λ
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i != 0 && j != 0 && matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
            else if(matrix[i][j] == 0){
                firstRow = (i==0?true:firstRow);
                firstCol = (j==0?true:firstCol);
            }
        }
    }

    // �û����˵�һ�к͵�һ��֮���������Ҫ��Ϊ0���к���
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0 || matrix[i][0]==0)
                matrix[i][j] = 0;
        }
    }

    //�����һ�еı�־λΪtrue����һ����Ҫ��0
    if(firstRow){
        for(int j=0;j<n;j++)
            matrix[0][j] = 0;
    }

    //�����һ�еı�־λΪtrue,��һ����Ҫ��0
    if(firstCol){
        for(int i=0;i<m;i++){
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    int m, n;
    cout << "����������������" << endl;
    cin >> m;

    cout << "����������������" << endl;
    cin >> n;

    cout << "���������" << endl;

    vector<vector<int> > matrix(m);
    for(unsigned int i=0;i<matrix.size();i++){
        matrix[i].resize(n);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }

    setMatrixZero(matrix,m,n);
    cout << "��0��ľ���Ϊ��" << endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
