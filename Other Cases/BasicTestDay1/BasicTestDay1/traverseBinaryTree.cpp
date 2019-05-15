/*前序，中序，后序遍历二叉树*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct treeNode {
	int val;
	treeNode* left;
	treeNode* right;

	treeNode(int value) {
		val = value;
		left = NULL;
		right = NULL;
	}
};

//层次序建立二叉树；利用完全二叉树在数组索引上的性质
treeNode* createTree(vector<int> nums) {
	vector<treeNode*> nodelist;  //先将int数组中的元素建成树节点

	for (int i = 0; i < nums.size(); i++) {
		treeNode* newNode = new treeNode(nums[i]);
		nodelist.push_back(newNode);
	}

	//根据索引规律连接二叉树
	for (int i = 0; i < nums.size() / 2 - 1; i++) {
		treeNode* parent = nodelist[i];
		parent->left = nodelist[2 * i + 1];
		parent->right = nodelist[2 * i + 2];
	}

	//当数组个数为奇数时，最后一个父节点才有右孩子
	int lastParentIdx = nums.size() / 2 - 1;
	treeNode* lastParent = nodelist[lastParentIdx];
	lastParent->left = nodelist[lastParentIdx * 2 + 1];
	if (nums.size() % 2 != 0) {
		lastParent->right = nodelist[lastParentIdx * 2 + 2];
	}

	treeNode* root = nodelist[0];  //取出根节点
	return root;
}

//递归：前序遍历二叉树，输出节点的值
void pre_traverse(treeNode* root) {
	//退出条件
	if (root == NULL) {
		return;
	}
	cout << root->val << " ";
	pre_traverse(root->left);
	pre_traverse(root->right);
}

//非递归：前序遍历二叉树，输出节点的值
void preTraverse(treeNode* root) {

	stack<treeNode*> s;
	s.push(root);  //根节点入栈
	while (!s.empty()) {
		treeNode* p = s.top();  //取栈顶元素的值
		s.pop();
		cout << p->val << " ";   //先输出根节点的值

		if (p->right != NULL) {
			s.push(p->right);
		}
		if (p->left != NULL) {
			s.push(p->left);
		}
	}
}


//递归：中序遍历二叉树，输出节点的值
void in_traverse(treeNode* root) {
	if (root == NULL) {
		return;
	}
	in_traverse(root->left);
	cout << root->val << " ";
	in_traverse(root->right);
}

//非递归：中序遍历二叉树，输出节点的值
void inTraverse(treeNode* root) {
	stack<treeNode*> s;
	s.push(root);

	while (!s.empty()) {
		treeNode* p = s.top();   //仅取栈顶元素值，而不是出栈

		if (p->left != NULL) {
			s.push(p->left);   //依次进入左孩子
			p = p->left;
		}
		else {
			cout << p->val << " ";
			s.pop();   

			p = s.top();
			cout << p->val << " ";
			s.pop();

			if (p->right != NULL) {
				s.push(p->right);
				p = p->right;
			}
		}
	}
}


//递归：后序遍历二叉树，输出节点的值
void post_traverse(treeNode* root) {
	if (root == NULL) {
		return;
	}
	post_traverse(root->left);
	post_traverse(root->right);
	cout << root->val << " ";
}

//非递归：后序遍历二叉树，输出节点的值
void postTraverse(treeNode* root) {
	stack<treeNode*> s;
	s.push(root);     //根节点入栈

	treeNode* q = root;    //q保存上次访问过(这里指出栈并进行过输出)的节点
	treeNode* p = root;    //p负责遍历

	while (p != NULL || !s.empty()) {
		p = s.top();

		while (p != NULL) {   //一直走到左孩子为空，一直入栈
			s.push(p);
			p = p->left;
		}

		p = s.top();  //查看当前栈顶元素

		if (p->right == NULL || p->right == q) {  //右孩子为空或已访问过，则可以输出根节点
			cout << p->val << " ";
			s.pop();
			q = p;
			p = NULL;    //△注意这里一定要将遍历节点置空，因为当前节点的左右孩子都已经进栈了，其使命完成
		}
		else {  //如果右孩子不为空且右孩子未被访问过，右孩子进栈
			//s.push(p->right);
			p = p->right;
		}
	}
}

/*
int main() {
	//建立二叉树
	vector<int> nums;
	int num;
	cout << "请输入二叉树中的元素（依层次序）：" << endl;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	treeNode* root = createTree(nums);
	//pre_traverse(root);
	//in_traverse(root);
	//post_traverse(root);

	//preTraverse(root);
	//inTraverse(root);
	postTraverse(root);
}
*/