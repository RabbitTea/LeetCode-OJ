#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include <iostream>

using namespace std;

/**模板类定义二叉树结点类**/
template<class T>
class BSTNode{
public:
    T key; // 结点的关键字
    BSTNode *left; // 结点的左孩子指针
    BSTNode *right; // 结点的右孩子指针
    BSTNode *parent; // 结点的父结点指针

    //带参的构造方法
    BSTNode(T k, BSTNode *l, BSTNode *r, BSTNode *p){
        key = k;
        left = l;
        right = r;
        parent = p;
    }
};

/**模板类定义二叉搜索树类，并声明其相关操作**/
template<class T>
class BSTree{
public:
    BSTNode<T> *root;

public:
    BSTree();
    ~BSTree();

    void inOrder(BSTNode<T> *tree) const; // 中序遍历二叉搜索树

    BSTNode<T>* Minimum(BSTNode<T> *tree); // 查找以tree为根结点的二叉搜索树中最小结点，返回指向最小结点的指针
    BSTNode<T>* Maximum(BSTNode<T> *tree); // 查找以tree为根结点的二叉搜索树中最大结点，返回指向最大结点的指针

    BSTNode<T>* Successor(BSTNode<T> *x); // 查找结点x的后继结点
    BSTNode<T>* Predecessor(BSTNode<T> *x); //查找结点x的前驱结点

    BSTNode<T>* Search(BSTNode<T> *tree, T key) const; // （递归实现）查找二叉搜索树tree中键值为key的点，返回其指针
    BSTNode<T>* cycleSearch(BSTNode<T> *tree, T key) const; // （非递归实现）查找二叉搜索树tree中键值为key的点，返回其指针void

    void BSTree_Insert(BSTree<T> *tree, BSTNode<T> *z); // 插入结点z到二叉搜索树中
    //void Insert(T key); // 将键值key插入到二叉搜索树中

    void BSTree_Transplant(BSTree<T> *tree, BSTNode<T> *u, BSTNode<T> *v); // 删除操作的辅助过程：用以v为根的子树替换以u为根的子树
    void BSTree_Delete(BSTree<T> *tree, BSTNode<T> *z); // 从二叉搜索树中删除结点z
};

//构造函数
template<class T>
BSTree<T>::BSTree(){
    root = NULL;
}

//中序遍历二叉搜索树
template<class T>
void BSTree<T>::inOrder(BSTNode<T> *tree) const
{
    if(tree != NULL){
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }
}

// 查找以tree为根结点的二叉搜索树中最小结点，返回指向最小结点的指针
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

// 查找以tree为根结点的二叉搜索树中最大结点，返回指向最大结点的指针
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
* 查找结点x的后继结点【即存储链表中比结点x大的结点中的最小结点】
* 其有两种情况：
*      ① x存在右孩子，那么在x的右子树中查找最左处的孩子结点[即以x右孩子为根的子树的最小结点]，即为x的后继结点
*      ② x不存在右孩子，仍分两种情况：
                 x是其父结点的左孩子，则x的后继结点为其父结点
                 x是其父结点的右孩子，则向上找x的【最低】祖先，要求为该结点具有左孩子【注意根结点的父结点为NULL】
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
* 查找结点x的前驱结点【即存储链表中比结点x小的结点中的最大结点】
* 其有两种情况：
*      ① x存在左孩子，那么在x的左子树中查找最右处的孩子结点[即以x左孩子为根的子树的最大结点]，即为x的前驱结点
*      ② x不存在左孩子，仍分两种情况：
                 x是其父结点的右孩子，则x的前驱结点为其父结点
                 x是其父结点的左孩子，则向上找x的【最低】祖先，要求为该结点具有右孩子【注意根结点的父结点为NULL】
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

// （递归实现）查找二叉搜索树tree中键值为key的点，返回其指针
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

// （非递归实现）查找二叉搜索树tree中键值为key的点，返回其指针
// 【核心思想是用一个循环不断向下查找】
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
* 向二叉搜索树中插入一个结点z，该结点具有key值，其左孩子为空，右孩子也为空
* 关键思想是设定一个x不为空的循环，通过比较z->key值与x->key值向下遍历二叉搜索树，直到某个叶子结点的下一个空结点；
           这个空结点就是将要放置的z结点的位置；退出循环后再通过一次比较确定z的位置是在左边还是右边;
           【注意在循环中每次x要往下遍历前先用y保存x的位置】
**/
template<class T>
void BSTree<T>::BSTree_Insert(BSTree<T> *tree, BSTNode<T> *z)
{
    BSTNode<T> *x = tree->root;
    BSTNode<T> *y = NULL;

    // 查找z的插入位置
    while(x != NULL){
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    // 对z进行插入
    z->parent = y;
    if(y == NULL) // 考虑树为空的情况，令z为根结点
        tree->root = z;
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;
}


/**
* 从二叉搜索树中删除结点z，需要一个辅助函数Transplant，用来进行子树的替换
* 按关键思想来分主要有三大种情况：
* 一、z结点没有孩子；此时直接删除z结点，将其父结点的对应孩子置空即可[具体编程时又要讨论z是其父的左孩子还是右孩子的情况]
* 二、z结点只有一个孩子；用以孩子为根的子树替换以z为根的子树[具体编程时又要分z有左孩子还是右孩子]
* 三、z结点有两个孩子；此时需要找到z结点的后继结点，【其一定在z的右子树中，且没有左孩子】
                        分为两种情况：
                        ① y就是z的右孩子；此时用以y为根的子树替换以z为根的子树【y只有右子树】
                        ② y位于z的右子树但不是z的右孩子；此时先用y的右子树替换y，再把y放到z的位置，使z的左右孩子成为y的左右孩子
**/

/** 用以v为根的子树替换以u为根的子树，并成为u的双亲的孩子结点**/
template<class T>
void BSTree<T>::BSTree_Transplant(BSTree<T> *tree, BSTNode<T> *u, BSTNode<T> *v)
{
    if(u->parent == NULL)
        tree->root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    //成为孩子后要规定其父亲
    if(v != NULL)
        v->parent = u->parent;
}

/**删除z结点**/
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
