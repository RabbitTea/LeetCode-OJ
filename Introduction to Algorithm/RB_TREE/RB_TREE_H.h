#ifndef RB_TREE_H_H_INCLUDED
#define RB_TREE_H_H_INCLUDED

#include <vector>

//红黑树结点结构体
struct RB_TREE_NODE{
    int key;
    int color; //颜色设为整型值，用-1代表黑色，1代表红色
    RB_TREE_NODE *left;
    RB_TREE_NODE *right;
    RB_TREE_NODE *p;

    //含有一个参数的构造方法，该参数传递结点中的值
    public: RB_TREE_NODE(int a){
            key = a;
            color = -1; //颜色默认为黑
            left = 0;
            right = 0;
            p = 0;
        }

        //析构函数
        ~RB_TREE_NODE(){}
};

static RB_TREE_NODE NIL = 0; //定义静态全局变量NIL表示空节点
#define PNIL (&NIL)  //将指向空节点的指针命名为PNIL（PNIL为哨兵）【注意：只有哨兵没有父节点】

//红黑树结构体
struct RB_TREE{
    RB_TREE_NODE *root = PNIL;

    //无参构造函数
    RB_TREE(){
        root -> left = PNIL;
        root -> right = PNIL;
        root -> p = PNIL;
    }

    void RB_LEFT_ROTATE(RB_TREE *root, RB_TREE_NODE *x); //以x为支点进行左旋
    void RB_RIGHT_ROTATE(RB_TREE *root, RB_TREE_NODE *x); //以x为支点进行右旋

    void RB_TREE_INSERT(RB_TREE *root, RB_TREE_NODE *z); //插入新的结点z
    void RB_TREE_INSERT_FIXUP(RB_TREE *root, RB_TREE_NODE *z); //插入结点z后从z开始进行修复

    RB_TREE_NODE* RB_TREE_MINMUM(RB_TREE_NODE* x); //查找以x为根【节点】的树中最小值，返回含最小值的节点
    RB_TREE_NODE* RB_TREE_MAXMUM(RB_TREE_NODE* x); //查找以x为根【节点】的树中最大值，返回含最大值的节点
    RB_TREE_NODE* RB_TREE_SUCCESSOR(RB_TREE *root, RB_TREE_NODE *x); //查找x节点的后继节点
    void RB_TRANSPLANT(RB_TREE *root,RB_TREE_NODE *u,RB_TREE_NODE *v); //用以节点v为根的树替换以节点u为根的树
    void RB_TREE_DELETE(RB_TREE *root, RB_TREE_NODE *z); //删除红黑树中的节点z
    void RB_TREE_DELETE_FIXUP(RB_TREE* root, RB_TREE_NODE*z); //删除节点z后对红黑树进行调整，使其满足红黑树的条件

    RB_TREE_NODE* RB_SEARCH(RB_TREE* root, int value); //搜索节点值为value的节点，并返回，搜索不到返回PNIL
    //std::vector<RB_TREE_NODE*> RB_SEARCH_ALL(RB_TREE* root, int value); //搜索所有节点值为value的节点并返回
};

void RB_TREE::RB_LEFT_ROTATE(RB_TREE *root, RB_TREE_NODE *x){
    RB_TREE_NODE *y = x -> right;
    x -> right = y ->left;
    if(y -> left != PNIL)
            y -> left -> p = x;
    y -> p = x -> p;
    if(x ->p == PNIL){
        root -> root = y;
    }
    else{
        if(x == x -> p -> left)
            x -> p -> left = y;
        else
            x -> p -> right = y;
    }
    y -> left = x;
    x -> p = y;
}

void RB_TREE::RB_RIGHT_ROTATE(RB_TREE *root, RB_TREE_NODE *x){
    RB_TREE_NODE *y = x -> left;
    x -> left = y -> right;

    if(y -> right != PNIL){
        y -> right -> p = x;
    }
    y -> p = x -> p;
    if(x -> p == PNIL){
        root -> root = y;
    }
    else{
        if(x == x -> p -> left)
            x -> p -> left = y;
        else
            x -> p -> right = y;
    }
    y -> right = x;
    x -> p = y;
}

//红黑树插入节点z
void RB_TREE::RB_TREE_INSERT(RB_TREE *root, RB_TREE_NODE *z){
    z -> left = PNIL;
    z -> right = PNIL; //先把新节点z的左孩子和右孩子设置为哨兵
    RB_TREE_NODE *x = RB_TREE::root;
    RB_TREE_NODE *y = PNIL;

    while(x != PNIL){
        y = x;
        if(z -> key < x -> key)
            x = x -> left;
        else
            x = x -> right;
    }
    if(y == PNIL)
        root -> root = z;
    else if(z -> key < y -> key){
        y -> left = z;
    }
    else{
        y -> right = z;
    }
    z -> p = y;
    z -> color = 1; //总是令插入的新节点的颜色为红色

    RB_TREE_INSERT_FIXUP(root,z); //调用修复函数进行修复
}

/**
* 对于插入修复的思路
  【注意每次调整颜色+旋转修复后向上改变当前修复节点z，不停地循环修复，直到z为根】
  大类情况：
    判断z的父亲是左子还是右子要在前面
    一、z结点为根：插入后直接令z结点的颜色为黑色
    二、z结点不为根（又分为两种情况）：
        <1> z的父节点为黑色————插入后不会改变红黑树的性质
        <2> z的父节点为红色————又分为两种情况（z的父节点是左子还是右子会在后面考虑）
               1. z的叔叔节点为红色；此时，对于父为左右子还是z为左右子都没有区别，均为同一种处理方法。
                  处理办法：将父亲和叔叔变为黑色，祖父变为红色，更新当前修复节点为z的祖父。
               2. z的叔叔节点为黑色（这是最重要也是最复杂的一种情况）；
                  此时，如果父亲为左子，则先判断处理z为右子①的情况，更新当前修复节点z为其父亲，并以
                                                      当前修复节点（原来z的父亲）为支点左旋。
                                            再判断处理z为左子②的情况（是对①的修复导致了②过程的发生），
                                                       将z的父亲节点变为黑色，祖父节点变为红色，并以祖父
                                                       为支点右旋。
                  如果父亲为右子，过程同理，只不过先处理z为左子的情况，进行的是右旋；
                                                    再处理z为右子的情况，进行的是左旋；
    最后使根节点的颜色变为黑色。
*/

void RB_TREE::RB_TREE_INSERT_FIXUP(RB_TREE *root, RB_TREE_NODE *z){
    while(z -> p -> color == 1 && z -> p != PNIL){//如果z的父亲节点为红色且z不是根节点
        if(z->p == z->p->p->left){ //如果z的父亲是左子
            RB_TREE_NODE *y = z->p->p->right; //y保存叔叔节点
            if(y->color == 1){//z的叔叔节点为红色
                z->p->color = -1;
                y->color = -1;
                z->p->p->color = 1;
                z = z->p->p;//更新当前修复节点z为z的祖父
            }
            else{//z的叔叔节点为黑色
                if(z == z->p->right){//z为右子
                    z = z->p;
                    RB_LEFT_ROTATE(root,z);
                }
                else{//z为左子
                    z->p->color = -1;
                    z->p->p->color = 1;
                    RB_RIGHT_ROTATE(root,z->p->p);
                }
            }
        }
        else{ //如果z的父亲是右子
            RB_TREE_NODE *y = z->p->p->left;
            if(y->color == 1){
                z->p->color = -1;
                y->color = -1;
                z->p->p->color = 1;
                z = z->p->p;
            }
            else{
                if(z == z->p->left){ //z为左子
                    z = z->p;
                    RB_RIGHT_ROTATE(root,z);
                }
                else{ //z为右子
                    z->p->color = -1;
                    z->p->p->color = 1;
                    RB_LEFT_ROTATE(root,z->p->p);
                }
            }
        }
    }
    root->root->color = -1;//最后令根节点的颜色为黑色
}

/**
* 红黑树的删除以及删除修复操作比较复杂，需要用到几个基本函数：
* 查找以x为根的树中最小值；查找以x为根的树中最大值；查找x节点的后继节点；用以节点v为根的树替换以节点u为根的树；
* 这四个基本函数都等同于普通二叉搜索树的基本操作
*/

//查找以x为根的树中最小值
RB_TREE_NODE* RB_TREE::RB_TREE_MINMUM(RB_TREE_NODE *x){
    while(x->left != PNIL){
        x = x->left;
    }
    return x;
}

//查找以x为根的树中最大值
RB_TREE_NODE* RB_TREE::RB_TREE_MAXMUM(RB_TREE_NODE *x){
    while(x->right != PNIL){
        x = x->right;
    }
    return x;
}

/**
* 查找x节点的后继节点并返回
*/
RB_TREE_NODE* RB_TREE::RB_TREE_SUCCESSOR(RB_TREE *root,RB_TREE_NODE *x){
    if(x == RB_TREE_MAXMUM(root->root))
        return x;
    if(x->right != PNIL)
        return RB_TREE_MINMUM(x->right);
    RB_TREE_NODE *y = x->p;
    while(y != PNIL && x == y->right){
        x = y;
        y = y->p;
    }
    return y;
}

/**
* 用以节点v为根的树替换以节点u为根的树
* 替换思路——分三种情况：
     1. 若u为根，则设v为根；
     2. 若u是左子，则令其父亲的左子为v；
     3. 若u是右子，则令其父亲的右子为v;
  这些孩子的链接完成后，要进行替换后节点u的父亲链接，这时要判断节点v是否为哨兵（PNIL）节点，
  如果v为哨兵，则因为哨兵没有父亲节点，所以不需要这一步的链接，其它需要。
*/
void RB_TREE::RB_TRANSPLANT(RB_TREE *root, RB_TREE_NODE *u, RB_TREE_NODE *v){
    if(u->p == PNIL)
        root->root = v;
    else if(u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;
    if(v != PNIL)
        v->p = u->p;
}

/**
* 对于红黑树的单纯删除操作，把它当成普通二叉查找树的删除即可；
* 分为三种情况：
     1. 被删除节点没有儿子，即为叶节点。那么，直接将该节点删除即可。
     2. 被删除节点只有一个儿子。那么，直接删除该节点，并用该节点的唯一子节点顶替它的位置。
     3. 被删除节点有两个儿子。那么，先找出它的后继节点；然后把“它的后继节点的内容”复制给“该节点的内容”；之后，删除“它的后继节点”。
        在这里，后继节点相当于替身，在将后继节点的内容复制给"被删除节点"之后，再将后继节点删除。这样就巧妙的将问题转换为"删除后继节点"的情况了。
        下面就考虑后继节点。 在"被删除节点"有两个非空子节点的情况下，它的后继节点不可能是双子非空。既然"该节点的后继节点"不可能双子都非空，
        就意味着"该节点的后继节点"要么没有儿子，要么只有一个儿子。若没有儿子，则按"情况1"进行处理；若只有一个儿子，则按"情况2"进行处理。
*/

void RB_TREE::RB_TREE_DELETE(RB_TREE *root, RB_TREE_NODE *z){
    RB_TREE_NODE *y = z;
    RB_TREE_NODE *x;
    int origin_color = y->color; //保存原定被删除节点的颜色

    if(z->left == PNIL){
        x = z->right;
        RB_TRANSPLANT(root,z,z->right);
    }
    else if(z->right == PNIL){
        x = z->left;
        RB_TRANSPLANT(root,z,z->left);
    }
    else{
        y = RB_TREE_MINMUM(z->right);
        origin_color = y->color;
        x = y->right;
        if(y->p == z){
            x->p = y; //保证x有父节点，防止y的子节点都是哨兵（哨兵是没有父节点的）
        }
        else{
            RB_TRANSPLANT(root,y,y->right);
            y->right = z->right;
            y->right->p = y;
        }
        RB_TRANSPLANT(root,z,y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;

        z->p = 0;

        z->right = 0;
        z->left = 0;
        delete z;
    }
    if(origin_color == -1){
        RB_TREE_DELETE_FIXUP(root,x);
    }
}

/**
* 删除节点后进行红黑树性质修复的操作
*/

void RB_TREE:: RB_TREE_DELETE_FIXUP(RB_TREE* root, RB_TREE_NODE*z)
{
    while (z != root->root&&z->color == -1)
    {
        if (z == z->p->left)
        {
            RB_TREE_NODE* y = z->p->right;
            if (y->color == 1)   /////case1
            {
                y->color = -1;
                z->p->color = 1;
                RB_LEFT_ROTATE(root, z->p);
                y = z->p->right;   ////转到case2，3，4中的一种
            }
            if (y->left->color == -1&&y->right->color == -1)
            {
                y->color = 1;    ////case2
                z = z->p;
            }
            else
            {
                if (y->right->color == -1)
                {
                    y->left->color = -1;
                    y->color = 1;
                    RB_RIGHT_ROTATE(root, y);   ////case3 转到case4
                    y = z->p->right;
                }
                y->color = z->p->color;
                z->p->color = -1;          ////case4;
                y->right->color = -1;
                RB_LEFT_ROTATE(root, z->p);
                z = root->root;
            }
        }
        else             ////与以上left和right互换
        {
            RB_TREE_NODE* y = z->p->left;
            if (y->color == 1)
            {
                y->color = -1;
                z->p->color = 1;
                RB_RIGHT_ROTATE(root, z->p);
                y = z->p->left;
            }
            if (y->right->color == -1&&y->left->color == -1)
            {
                y->color = 1;
                z = z->p;
            }
            else
            {
                if (y->left->color == -1)
                {
                    y->right->color = -1;
                    y->color = 1;
                    RB_LEFT_ROTATE(root, y);
                    y = z->p->left;
                }
                y->color = z->p->color;
                z->p->color = -1;
                y->left->color = -1;
                RB_RIGHT_ROTATE(root, z->p);
                z = root->root;
            }
        }
    }
    z->color = -1;
}


/**
* 查找值为value的节点
*/
RB_TREE_NODE* RB_TREE::RB_SEARCH(RB_TREE* root, int value)
{
    RB_TREE_NODE* target = root->root;
    while (target != PNIL&&target->key != value)
    {
        if (value < target->key)
        {
            target = target->left;
        }
        else
        {
            target = target->right;
        }
    }
    return target;
}

#endif // RB_TREE_H_H_INCLUDED
