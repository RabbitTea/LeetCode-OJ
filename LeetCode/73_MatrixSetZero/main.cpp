/**
* @description: 给定一个m×n 矩阵，如果某个元素为0，则将其整个行和列都设置为0
* @idea: 使用恒定的O(1)的空间复杂度——原地保存要置0的行和列；
         选择第一行的元素保存对应的列是否要置0，选择第一列的元素保存对应的行是否要置0；
         设置两个标志位，分别表示第一行和第一列是否要置0；
         先扫描到第一行和第一列中的元素，判断其它行列中的元素是否要置0；最后再通过标志位判断是否给第一行和第一列置0；
         【关键是先置其它行列，再通过标志位置保存的行和列】
* @author: SA18225018
* @date: 2018/10/24
**/
#include <iostream>
#include <vector>

using namespace std;

void setMatrixZero(vector<vector<int> > &matrix,int m, int n){
    //注意一定要传matrix的引用，否则函数退出后传入的二维数组值不会改变
    bool firstRow = false; // 行标志位，初始为false，如果扫描到每一行的开头元素为0，则置为true，否则仍为false
    bool firstCol = false; // 列标志位，初始为false，如果扫描到每一列的开头元素为0，则置为true，否则仍为false

    //统计要置0的行和列，并设置第一行和第一列的标志位
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

    // 置换除了第一行和第一列之外的其它需要变为0的行和列
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0 || matrix[i][0]==0)
                matrix[i][j] = 0;
        }
    }

    //如果第一行的标志位为true，第一行需要置0
    if(firstRow){
        for(int j=0;j<n;j++)
            matrix[0][j] = 0;
    }

    //如果第一列的标志位为true,第一列需要置0
    if(firstCol){
        for(int i=0;i<m;i++){
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    int m, n;
    cout << "请输入矩阵的行数：" << endl;
    cin >> m;

    cout << "请输入矩阵的列数：" << endl;
    cin >> n;

    cout << "请输入矩阵：" << endl;

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
    cout << "置0后的矩阵为：" << endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
