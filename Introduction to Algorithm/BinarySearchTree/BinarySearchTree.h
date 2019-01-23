#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include <iostream>

using namespace std;

/**ģ���ඨ������������**/
template<class T>
class BSTNode{
public:
    T key; // ���Ĺؼ���
    BSTNode *left; // ��������ָ��
    BSTNode *right; // �����Һ���ָ��
    BSTNode *parent; // ���ĸ����ָ��

    //���εĹ��췽��
    BSTNode(T k, BSTNode *l, BSTNode *r, BSTNode *p){
        key = k;
        left = l;
        right = r;
        parent = p;
    }
};

/**ģ���ඨ������������࣬����������ز���**/
template<class T>
class BSTree{
public:
    BSTNode<T> *root;

public:
    BSTree();
    ~BSTree();

    void inOrder(BSTNode<T> *tree) const; // �����������������

    BSTNode<T>* Minimum(BSTNode<T> *tree); // ������treeΪ�����Ķ�������������С��㣬����ָ����С����ָ��
    BSTNode<T>* Maximum(BSTNode<T> *tree); // ������treeΪ�����Ķ���������������㣬����ָ��������ָ��

    BSTNode<T>* Successor(BSTNode<T> *x); // ���ҽ��x�ĺ�̽��
    BSTNode<T>* Predecessor(BSTNode<T> *x); //���ҽ��x��ǰ�����

    BSTNode<T>* Search(BSTNode<T> *tree, T key) const; // ���ݹ�ʵ�֣����Ҷ���������tree�м�ֵΪkey�ĵ㣬������ָ��
    BSTNode<T>* cycleSearch(BSTNode<T> *tree, T key) const; // ���ǵݹ�ʵ�֣����Ҷ���������tree�м�ֵΪkey�ĵ㣬������ָ��void

    void BSTree_Insert(BSTree<T> *tree, BSTNode<T> *z); // ������z��������������
    //void Insert(T key); // ����ֵkey���뵽������������

    void BSTree_Transplant(BSTree<T> *tree, BSTNode<T> *u, BSTNode<T> *v); // ɾ�������ĸ������̣�����vΪ���������滻��uΪ��������
    void BSTree_Delete(BSTree<T> *tree, BSTNode<T> *z); // �Ӷ�����������ɾ�����z
};

//���캯��
template<class T>
BSTree<T>::BSTree(){
    root = NULL;
}

//�����������������
template<class T>
void BSTree<T>::inOrder(BSTNode<T> *tree) const
{
    if(tree != NULL){
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }
}

// ������treeΪ�����Ķ�������������С��㣬����ָ����С����ָ��
template<class T>
BSTNode<T>* BSTree<T>::Minimum(BSTNode<T> *tree)
{
    if(tree == NULL)
        return NULL;

    BSTNode<T> *x = tree;
    while(x->left != NULL){
        x = x->left;
    }
    return x;
}

// ������treeΪ�����Ķ���������������㣬����ָ��������ָ��
template<class T>
BSTNode<T>* BSTree<T>::Maximum(BSTNode<T> *tree)
{
    if(tree == NULL)
        return NULL;

    BSTNode<T> *x = tree;void BSTree_Transplant(BSTNode<T> *u, BSTNode<T> *v);
    while(tree->right != NULL){
        x = x->right;
    }
    return x;
}

/**
* ���ҽ��x�ĺ�̽�㡾���洢�����бȽ��x��Ľ���е���С��㡿
* �������������
*      �� x�����Һ��ӣ���ô��x���������в������󴦵ĺ��ӽ��[����x�Һ���Ϊ������������С���]����Ϊx�ĺ�̽��
*      �� x�������Һ��ӣ��Է����������
                 x���丸�������ӣ���x�ĺ�̽��Ϊ�丸���
                 x���丸�����Һ��ӣ���������x�ġ���͡����ȣ�Ҫ��Ϊ�ý��������ӡ�ע������ĸ����ΪNULL��
**/
template<class T>
BSTNode<T>* BSTree<T>::Successor(BSTNode<T> *x)
{
    if(x->right != NULL){
        return Minimum(x->right);
    }

    BSTNode<T> *y = x->parent;
    while(y!=NULL && x==y->right){
        x = y;
        y = x->parent;
    }
    return y;
}

/**
* ���ҽ��x��ǰ����㡾���洢�����бȽ��xС�Ľ���е�����㡿
* �������������
*      �� x�������ӣ���ô��x���������в������Ҵ��ĺ��ӽ��[����x����Ϊ���������������]����Ϊx��ǰ�����
*      �� x���������ӣ��Է����������
                 x���丸�����Һ��ӣ���x��ǰ�����Ϊ�丸���
                 x���丸�������ӣ���������x�ġ���͡����ȣ�Ҫ��Ϊ�ý������Һ��ӡ�ע������ĸ����ΪNULL��
**/
template<class T>
BSTNode<T>* BSTree<T>::Predecessor(BSTNode<T> *x)
{
    if(x->left != NULL){
        return Maximum(x->left);
    }

    BSTNode<T> *y = x->parent;
    while(y!=NULL && x==y->left){
        x = y;
        y = x->parent;
    }
    return y;
}

// ���ݹ�ʵ�֣����Ҷ���������tree�м�ֵΪkey�ĵ㣬������ָ��
template<class T>
BSTNode<T>* BSTree<T>::Search(BSTNode<T> *tree, T key) const
{
    BSTNode<T> *x = tree;
    if(x==NULL || x->key==key){
        return x;
    }

    if(key < x->key)
        return Search(tree->left,key);
    else
        return Search(tree->right,key);
}

// ���ǵݹ�ʵ�֣����Ҷ���������tree�м�ֵΪkey�ĵ㣬������ָ��
// ������˼������һ��ѭ���������²��ҡ�
template<class T>
BSTNode<T>* BSTree<T>::cycleSearch(BSTNode<T> *tree, T key) const
{
    BSTNode<T> *x = tree;
    while(x!=NULL && x->key != key){
        if(key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

/**
* ������������в���һ�����z���ý�����keyֵ��������Ϊ�գ��Һ���ҲΪ��
* �ؼ�˼�����趨һ��x��Ϊ�յ�ѭ����ͨ���Ƚ�z->keyֵ��x->keyֵ���±���������������ֱ��ĳ��Ҷ�ӽ�����һ���ս�㣻
           ����ս����ǽ�Ҫ���õ�z����λ�ã��˳�ѭ������ͨ��һ�αȽ�ȷ��z��λ��������߻����ұ�;
           ��ע����ѭ����ÿ��xҪ���±���ǰ����y����x��λ�á�
**/
template<class T>
void BSTree<T>::BSTree_Insert(BSTree<T> *tree, BSTNode<T> *z)
{
    BSTNode<T> *x = tree->root;
    BSTNode<T> *y = NULL;

    // ����z�Ĳ���λ��
    while(x != NULL){
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    // ��z���в���
    z->parent = y;
    if(y == NULL) // ������Ϊ�յ��������zΪ�����
        tree->root = z;
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;
}


/**
* �Ӷ�����������ɾ�����z����Ҫһ����������Transplant�����������������滻
* ���ؼ�˼��������Ҫ�������������
* һ��z���û�к��ӣ���ʱֱ��ɾ��z��㣬���丸���Ķ�Ӧ�����ÿռ���[������ʱ��Ҫ����z���丸�����ӻ����Һ��ӵ����]
* ����z���ֻ��һ�����ӣ����Ժ���Ϊ���������滻��zΪ��������[������ʱ��Ҫ��z�����ӻ����Һ���]
* ����z������������ӣ���ʱ��Ҫ�ҵ�z���ĺ�̽�㣬����һ����z���������У���û�����ӡ�
                        ��Ϊ���������
                        �� y����z���Һ��ӣ���ʱ����yΪ���������滻��zΪ����������yֻ����������
                        �� yλ��z��������������z���Һ��ӣ���ʱ����y���������滻y���ٰ�y�ŵ�z��λ�ã�ʹz�����Һ��ӳ�Ϊy�����Һ���
**/

/** ����vΪ���������滻��uΪ��������������Ϊu��˫�׵ĺ��ӽ��**/
template<class T>
void BSTree<T>::BSTree_Transplant(BSTree<T> *tree, BSTNode<T> *u, BSTNode<T> *v)
{
    if(u->parent == NULL)
        tree->root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    //��Ϊ���Ӻ�Ҫ�涨�丸��
    if(v != NULL)
        v->parent = u->parent;
}

/**ɾ��z���**/
template<class T>
void BSTree<T>::BSTree_Delete(BSTree<T> *tree, BSTNode<T> *z)
{
    if(z->left == NULL)
        BSTree_Transplant(tree,z,z->right);
    else if(z->right == NULL)
        BSTree_Transplant(tree,z,z->left);
    else{
        BSTNode<T> *y = Minimum(z->right);
        if(y == z->right)
            BSTree_Transplant(tree,z,y);
        else{
            BSTree_Transplant(tree,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        y->left = z->left;
        y->left->parent = y;
    }
}

#endif // BINARYSEARCHTREE_H_INCLUDED
