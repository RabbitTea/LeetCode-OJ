/*
* @description���ж����ö������Ƿ���ͬ�����ṹ�ͽڵ��е�ֵ����ͬ���true����һ����ͬ���false��
* @idea��DFS˼�룬���������������ָ������ָ��ָ���������ĸ��ڵ㣬����������������±�����ÿ����һ��
         �ڵ㶼�Ա����ߵ�ֵ�Ƿ���ͬ(����ֵ�Ƿ�Ϊ�յ��жϣ���Ҳ�ǽṹ�Ƿ���ͬ���ж�)��ֱ���������ͬ
		 ʱ�ٻ���һ���ڵ�����Ƚϡ�
* @author��RabbitTea
* @date��2019/3/18
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Tree {

public:
	TreeNode* root;
	Tree() {
		//�ڹ��캯���г�ʼ�����ڵ�
		root = new TreeNode(0);
		root->left = NULL;
		root->right = NULL;
	}
 
	//����һ�ö�����
	/*
	* ������߹�������������������һ����ֵΪ-1����
	*/
public:
	TreeNode* create() {
		int value;
		cin >> value;
		root->val = value;   //����һ��ֵ�������ڵ�

		TreeNode* tmp = root;
		queue<TreeNode*> que;
			
		if (root != NULL) {
			que.push(tmp);   //�ڵ����
			while (!que.empty()) {
				tmp = que.front();   //�����ȡ�ö�ͷ��ֵ���ýڵ����ڶ��л���
				que.pop();   //��ͷԪ�س���

				int value;
				cin >> value;
				if (value != -1) {  //������������ע������-1��ʾ�������ڵ㣬�Ӷ�ʹ����Ϊ�գ���ֹѭ��
					TreeNode* newNode = new TreeNode(value);
					tmp->left = newNode;
					que.push(newNode);
				}

				cin >> value;
				if (value != -1) {  //����������
					TreeNode* newNode = new TreeNode(value);
					tmp->right = newNode;
					que.push(newNode);
				}
			}
		}
		
		return root;
	}
};

bool isSameTree(TreeNode* p, TreeNode* q) {

	//�ݹ��˳�����
	if (p == NULL ^ q == NULL) {   //^����Ϊ����������ʾp==NULL��q==NULLȡ��һ
		return false;
	}
	if (p == NULL && q == NULL) {
		return true;
	}
	if (p->val != q->val) {
		return false;
	}

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);    //&&��ʾ��·�룬������ݹ鵽��ߺ���ʱ���ֲ�ͬ�Ͳ����ж��Һ�����ֱ�����false��
}

int main() {
	//����������
	cout << "�������һ�ö�����" << endl;
	Tree t1;
	t1.create();

	cout << "������ڶ��ö�����" << endl;
	Tree t2;
	t2.create();

	bool res = isSameTree(t1.root, t2.root);
	cout << "���Ϊ��" << res << endl;
}