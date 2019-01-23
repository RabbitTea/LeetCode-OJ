#ifndef RB_TREE_H_H_INCLUDED
#define RB_TREE_H_H_INCLUDED

#include <vector>

//��������ṹ��
struct RB_TREE_NODE{
    int key;
    int color; //��ɫ��Ϊ����ֵ����-1�����ɫ��1�����ɫ
    RB_TREE_NODE *left;
    RB_TREE_NODE *right;
    RB_TREE_NODE *p;

    //����һ�������Ĺ��췽�����ò������ݽ���е�ֵ
    public: RB_TREE_NODE(int a){
            key = a;
            color = -1; //��ɫĬ��Ϊ��
            left = 0;
            right = 0;
            p = 0;
        }

        //��������
        ~RB_TREE_NODE(){}
};

static RB_TREE_NODE NIL = 0; //���徲̬ȫ�ֱ���NIL��ʾ�սڵ�
#define PNIL (&NIL)  //��ָ��սڵ��ָ������ΪPNIL��PNILΪ�ڱ�����ע�⣺ֻ���ڱ�û�и��ڵ㡿

//������ṹ��
struct RB_TREE{
    RB_TREE_NODE *root = PNIL;

    //�޲ι��캯��
    RB_TREE(){
        root -> left = PNIL;
        root -> right = PNIL;
        root -> p = PNIL;
    }

    void RB_LEFT_ROTATE(RB_TREE *root, RB_TREE_NODE *x); //��xΪ֧���������
    void RB_RIGHT_ROTATE(RB_TREE *root, RB_TREE_NODE *x); //��xΪ֧���������

    void RB_TREE_INSERT(RB_TREE *root, RB_TREE_NODE *z); //�����µĽ��z
    void RB_TREE_INSERT_FIXUP(RB_TREE *root, RB_TREE_NODE *z); //������z���z��ʼ�����޸�

    RB_TREE_NODE* RB_TREE_MINMUM(RB_TREE_NODE* x); //������xΪ�����ڵ㡿��������Сֵ�����غ���Сֵ�Ľڵ�
    RB_TREE_NODE* RB_TREE_MAXMUM(RB_TREE_NODE* x); //������xΪ�����ڵ㡿���������ֵ�����غ����ֵ�Ľڵ�
    RB_TREE_NODE* RB_TREE_SUCCESSOR(RB_TREE *root, RB_TREE_NODE *x); //����x�ڵ�ĺ�̽ڵ�
    void RB_TRANSPLANT(RB_TREE *root,RB_TREE_NODE *u,RB_TREE_NODE *v); //���Խڵ�vΪ�������滻�Խڵ�uΪ������
    void RB_TREE_DELETE(RB_TREE *root, RB_TREE_NODE *z); //ɾ��������еĽڵ�z
    void RB_TREE_DELETE_FIXUP(RB_TREE* root, RB_TREE_NODE*z); //ɾ���ڵ�z��Ժ�������е�����ʹ����������������

    RB_TREE_NODE* RB_SEARCH(RB_TREE* root, int value); //�����ڵ�ֵΪvalue�Ľڵ㣬�����أ�������������PNIL
    //std::vector<RB_TREE_NODE*> RB_SEARCH_ALL(RB_TREE* root, int value); //�������нڵ�ֵΪvalue�Ľڵ㲢����
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

//���������ڵ�z
void RB_TREE::RB_TREE_INSERT(RB_TREE *root, RB_TREE_NODE *z){
    z -> left = PNIL;
    z -> right = PNIL; //�Ȱ��½ڵ�z�����Ӻ��Һ�������Ϊ�ڱ�
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
    z -> color = 1; //�����������½ڵ����ɫΪ��ɫ

    RB_TREE_INSERT_FIXUP(root,z); //�����޸����������޸�
}

/**
* ���ڲ����޸���˼·
  ��ע��ÿ�ε�����ɫ+��ת�޸������ϸı䵱ǰ�޸��ڵ�z����ͣ��ѭ���޸���ֱ��zΪ����
  ���������
    �ж�z�ĸ��������ӻ�������Ҫ��ǰ��
    һ��z���Ϊ���������ֱ����z������ɫΪ��ɫ
    ����z��㲻Ϊ�����ַ�Ϊ�����������
        <1> z�ĸ��ڵ�Ϊ��ɫ������������󲻻�ı�����������
        <2> z�ĸ��ڵ�Ϊ��ɫ���������ַ�Ϊ���������z�ĸ��ڵ������ӻ������ӻ��ں��濼�ǣ�
               1. z������ڵ�Ϊ��ɫ����ʱ�����ڸ�Ϊ�����ӻ���zΪ�����Ӷ�û�����𣬾�Ϊͬһ�ִ�������
                  ����취�������׺������Ϊ��ɫ���游��Ϊ��ɫ�����µ�ǰ�޸��ڵ�Ϊz���游��
               2. z������ڵ�Ϊ��ɫ����������ҪҲ����ӵ�һ���������
                  ��ʱ���������Ϊ���ӣ������жϴ���zΪ���Ӣٵ���������µ�ǰ�޸��ڵ�zΪ�丸�ף�����
                                                      ��ǰ�޸��ڵ㣨ԭ��z�ĸ��ף�Ϊ֧��������
                                            ���жϴ���zΪ���Ӣڵ�������ǶԢٵ��޸������ˢڹ��̵ķ�������
                                                       ��z�ĸ��׽ڵ��Ϊ��ɫ���游�ڵ��Ϊ��ɫ�������游
                                                       Ϊ֧��������
                  �������Ϊ���ӣ�����ͬ��ֻ�����ȴ���zΪ���ӵ���������е���������
                                                    �ٴ���zΪ���ӵ���������е���������
    ���ʹ���ڵ����ɫ��Ϊ��ɫ��
*/

void RB_TREE::RB_TREE_INSERT_FIXUP(RB_TREE *root, RB_TREE_NODE *z){
    while(z -> p -> color == 1 && z -> p != PNIL){//���z�ĸ��׽ڵ�Ϊ��ɫ��z���Ǹ��ڵ�
        if(z->p == z->p->p->left){ //���z�ĸ���������
            RB_TREE_NODE *y = z->p->p->right; //y��������ڵ�
            if(y->color == 1){//z������ڵ�Ϊ��ɫ
                z->p->color = -1;
                y->color = -1;
                z->p->p->color = 1;
                z = z->p->p;//���µ�ǰ�޸��ڵ�zΪz���游
            }
            else{//z������ڵ�Ϊ��ɫ
                if(z == z->p->right){//zΪ����
                    z = z->p;
                    RB_LEFT_ROTATE(root,z);
                }
                else{//zΪ����
                    z->p->color = -1;
                    z->p->p->color = 1;
                    RB_RIGHT_ROTATE(root,z->p->p);
                }
            }
        }
        else{ //���z�ĸ���������
            RB_TREE_NODE *y = z->p->p->left;
            if(y->color == 1){
                z->p->color = -1;
                y->color = -1;
                z->p->p->color = 1;
                z = z->p->p;
            }
            else{
                if(z == z->p->left){ //zΪ����
                    z = z->p;
                    RB_RIGHT_ROTATE(root,z);
                }
                else{ //zΪ����
                    z->p->color = -1;
                    z->p->p->color = 1;
                    RB_LEFT_ROTATE(root,z->p->p);
                }
            }
        }
    }
    root->root->color = -1;//�������ڵ����ɫΪ��ɫ
}

/**
* �������ɾ���Լ�ɾ���޸������Ƚϸ��ӣ���Ҫ�õ���������������
* ������xΪ����������Сֵ��������xΪ�����������ֵ������x�ڵ�ĺ�̽ڵ㣻���Խڵ�vΪ�������滻�Խڵ�uΪ��������
* ���ĸ�������������ͬ����ͨ�����������Ļ�������
*/

//������xΪ����������Сֵ
RB_TREE_NODE* RB_TREE::RB_TREE_MINMUM(RB_TREE_NODE *x){
    while(x->left != PNIL){
        x = x->left;
    }
    return x;
}

//������xΪ�����������ֵ
RB_TREE_NODE* RB_TREE::RB_TREE_MAXMUM(RB_TREE_NODE *x){
    while(x->right != PNIL){
        x = x->right;
    }
    return x;
}

/**
* ����x�ڵ�ĺ�̽ڵ㲢����
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
* ���Խڵ�vΪ�������滻�Խڵ�uΪ������
* �滻˼·���������������
     1. ��uΪ��������vΪ����
     2. ��u�����ӣ������丸�׵�����Ϊv��
     3. ��u�����ӣ������丸�׵�����Ϊv;
  ��Щ���ӵ�������ɺ�Ҫ�����滻��ڵ�u�ĸ������ӣ���ʱҪ�жϽڵ�v�Ƿ�Ϊ�ڱ���PNIL���ڵ㣬
  ���vΪ�ڱ�������Ϊ�ڱ�û�и��׽ڵ㣬���Բ���Ҫ��һ�������ӣ�������Ҫ��
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
* ���ں�����ĵ���ɾ������������������ͨ�����������ɾ�����ɣ�
* ��Ϊ���������
     1. ��ɾ���ڵ�û�ж��ӣ���ΪҶ�ڵ㡣��ô��ֱ�ӽ��ýڵ�ɾ�����ɡ�
     2. ��ɾ���ڵ�ֻ��һ�����ӡ���ô��ֱ��ɾ���ýڵ㣬���øýڵ��Ψһ�ӽڵ㶥������λ�á�
     3. ��ɾ���ڵ����������ӡ���ô�����ҳ����ĺ�̽ڵ㣻Ȼ��ѡ����ĺ�̽ڵ�����ݡ����Ƹ����ýڵ�����ݡ���֮��ɾ�������ĺ�̽ڵ㡱��
        �������̽ڵ��൱�������ڽ���̽ڵ�����ݸ��Ƹ�"��ɾ���ڵ�"֮���ٽ���̽ڵ�ɾ��������������Ľ�����ת��Ϊ"ɾ����̽ڵ�"������ˡ�
        ����Ϳ��Ǻ�̽ڵ㡣 ��"��ɾ���ڵ�"�������ǿ��ӽڵ������£����ĺ�̽ڵ㲻������˫�ӷǿա���Ȼ"�ýڵ�ĺ�̽ڵ�"������˫�Ӷ��ǿգ�
        ����ζ��"�ýڵ�ĺ�̽ڵ�"Ҫôû�ж��ӣ�Ҫôֻ��һ�����ӡ���û�ж��ӣ���"���1"���д�����ֻ��һ�����ӣ���"���2"���д���
*/

void RB_TREE::RB_TREE_DELETE(RB_TREE *root, RB_TREE_NODE *z){
    RB_TREE_NODE *y = z;
    RB_TREE_NODE *x;
    int origin_color = y->color; //����ԭ����ɾ���ڵ����ɫ

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
            x->p = y; //��֤x�и��ڵ㣬��ֹy���ӽڵ㶼���ڱ����ڱ���û�и��ڵ�ģ�
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
* ɾ���ڵ����к���������޸��Ĳ���
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
                y = z->p->right;   ////ת��case2��3��4�е�һ��
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
                    RB_RIGHT_ROTATE(root, y);   ////case3 ת��case4
                    y = z->p->right;
                }
                y->color = z->p->color;
                z->p->color = -1;          ////case4;
                y->right->color = -1;
                RB_LEFT_ROTATE(root, z->p);
                z = root->root;
            }
        }
        else             ////������left��right����
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
* ����ֵΪvalue�Ľڵ�
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
