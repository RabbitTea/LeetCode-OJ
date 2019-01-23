#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

static int arr[] = {8,3,5,2,7}; // 定义一个静态数组，存入默认值
static int len = 5;

int main()
{
    BSTree<int> *tree = new BSTree<int>();

    cout << "*****构建一棵二叉搜索树，并向其中传值*****" << endl;
    cout << "添加元素键值: ";
    for(int i=0;i<len;i++){
        cout << arr[i] << " ";
        BSTNode<int> *z = new BSTNode<int>(arr[i],NULL,NULL,NULL);
        tree->BSTree_Insert(tree,z);
    }
    cout << endl;
    cout << endl;

    cout << "*****中序遍历二叉搜索树*****" << endl;
    tree->inOrder(tree->root);
    cout << endl;
     cout << endl;

    cout << "*****二叉搜索树中的最大值*****" << endl;
    BSTNode<int> *tmax = tree->Maximum(tree->root);
    cout << "max=" << tmax->key << endl;
    cout << endl;

    cout << "*****二叉搜索树中的最小值*****" << endl;
    BSTNode<int> *tmin = tree->Minimum(tree->root);
    cout << "min=" << tmin->key << endl;
    cout << endl;

    cout << "*****删除键值为3的结点*****" << endl;
    BSTNode<int> *z = tree->Search(tree->root,3);//先找到键值为3的结点
    tree->BSTree_Delete(tree,z);
    cout << endl;

    cout << "*****删除后中序遍历二叉搜索树*****" << endl;
    tree->inOrder(tree->root);

    return 0;
}
