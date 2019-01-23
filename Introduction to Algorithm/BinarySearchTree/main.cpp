#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

static int arr[] = {8,3,5,2,7}; // ����һ����̬���飬����Ĭ��ֵ
static int len = 5;

int main()
{
    BSTree<int> *tree = new BSTree<int>();

    cout << "*****����һ�ö������������������д�ֵ*****" << endl;
    cout << "���Ԫ�ؼ�ֵ: ";
    for(int i=0;i<len;i++){
        cout << arr[i] << " ";
        BSTNode<int> *z = new BSTNode<int>(arr[i],NULL,NULL,NULL);
        tree->BSTree_Insert(tree,z);
    }
    cout << endl;
    cout << endl;

    cout << "*****�����������������*****" << endl;
    tree->inOrder(tree->root);
    cout << endl;
     cout << endl;

    cout << "*****�����������е����ֵ*****" << endl;
    BSTNode<int> *tmax = tree->Maximum(tree->root);
    cout << "max=" << tmax->key << endl;
    cout << endl;

    cout << "*****�����������е���Сֵ*****" << endl;
    BSTNode<int> *tmin = tree->Minimum(tree->root);
    cout << "min=" << tmin->key << endl;
    cout << endl;

    cout << "*****ɾ����ֵΪ3�Ľ��*****" << endl;
    BSTNode<int> *z = tree->Search(tree->root,3);//���ҵ���ֵΪ3�Ľ��
    tree->BSTree_Delete(tree,z);
    cout << endl;

    cout << "*****ɾ���������������������*****" << endl;
    tree->inOrder(tree->root);

    return 0;
}
