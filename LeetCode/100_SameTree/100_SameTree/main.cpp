/*
* @description：判断两棵二叉树是否相同，即结构和节点中的值均相同输出true，有一处不同输出false；
* @idea：DFS思想，即深度优先搜索，指定两个指针指向两棵树的根节点，按深度优先依次向下遍历，每遍历一个
         节点都对比两者的值是否相同(包括值是否为空的判断，这也是结构是否相同的判断)。直到最深处都相同
		 时再回溯一个节点继续比较。
* @author：RabbitTea
* @date：2019/3/18
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
		//在构造函数中初始化根节点
		root = new TreeNode(0);
		root->left = NULL;
		root->right = NULL;
	}
 
	//构建一棵二叉树
	/*
	* 边输入边构建；结束条件是输入一整组值为-1的数
	*/
public:
	TreeNode* create() {
		int value;
		cin >> value;
		root->val = value;   //将第一个值赋给根节点

		TreeNode* tmp = root;
		queue<TreeNode*> que;
			
		if (root != NULL) {
			que.push(tmp);   //节点入队
			while (!que.empty()) {
				tmp = que.front();   //这里仅取得队头的值，该节点仍在队列汇中
				que.pop();   //队头元素出队

				int value;
				cin >> value;
				if (value != -1) {  //建立左子树；注意输入-1表示不建立节点，从而使队列为空，终止循环
					TreeNode* newNode = new TreeNode(value);
					tmp->left = newNode;
					que.push(newNode);
				}

				cin >> value;
				if (value != -1) {  //建立右子树
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

	//递归退出条件
	if (p == NULL ^ q == NULL) {   //^符号为异或符，即表示p==NULL和q==NULL取其一
		return false;
	}
	if (p == NULL && q == NULL) {
		return true;
	}
	if (p->val != q->val) {
		return false;
	}

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);    //&&表示短路与，即如果递归到左边孩子时发现不同就不用判断右孩子了直接输出false；
}

int main() {
	//创建二叉树
	cout << "请输入第一棵二叉树" << endl;
	Tree t1;
	t1.create();

	cout << "请输入第二棵二叉树" << endl;
	Tree t2;
	t2.create();

	bool res = isSameTree(t1.root, t2.root);
	cout << "结果为：" << res << endl;
}