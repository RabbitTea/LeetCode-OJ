#include "RB_TREE_H.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void print(RB_TREE* root)     //从小到大输出所有的树节点值
{
    RB_TREE_NODE* pmin = root->RB_TREE_MINMUM(root->root);
    RB_TREE_NODE* pmax = root->RB_TREE_MAXMUM(root->root);
    int i = 0;
    while (true)
    {
        if (i++ % 10 == 0)cout << endl;
        cout << pmin->key << " ";
        if (pmin == pmax)break;
        pmin = root->RB_TREE_SUCCESSOR(root, pmin);
    }

    cout <<endl<< endl << "===================================" << endl;
}

int main()
{
    int a[1000];
    for (int i = 0; i < 1000; i++)
    {
        a[i] = rand() % 100;
    }

    RB_TREE* root = new RB_TREE();
    for (int i = 0; i < 100; i++)
    {
        RB_TREE_NODE* z = new RB_TREE_NODE(a[i]);
        root->RB_TREE_INSERT(root,z);
    }

    cout << "====================================" << endl;
    //RB_TREE_NODE* pmin = root->RB_TREE_MINMUM(root->root);
    //RB_TREE_NODE* pmax = root->RB_TREE_MAXMUM(root->root);
    print(root);
    cout << endl << endl << "=================================" << endl;
    return 0;
}
