/*ǰ�����򣬺������������*/

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

//���������������������ȫ�����������������ϵ�����
treeNode* createTree(vector<int> nums) {
	vector<treeNode*> nodelist;  //�Ƚ�int�����е�Ԫ�ؽ������ڵ�

	for (int i = 0; i < nums.size(); i++) {
		treeNode* newNode = new treeNode(nums[i]);
		nodelist.push_back(newNode);
	}

	//���������������Ӷ�����
	for (int i = 0; i < nums.size() / 2 - 1; i++) {
		treeNode* parent = nodelist[i];
		parent->left = nodelist[2 * i + 1];
		parent->right = nodelist[2 * i + 2];
	}

	//���������Ϊ����ʱ�����һ�����ڵ�����Һ���
	int lastParentIdx = nums.size() / 2 - 1;
	treeNode* lastParent = nodelist[lastParentIdx];
	lastParent->left = nodelist[lastParentIdx * 2 + 1];
	if (nums.size() % 2 != 0) {
		lastParent->right = nodelist[lastParentIdx * 2 + 2];
	}

	treeNode* root = nodelist[0];  //ȡ�����ڵ�
	return root;
}

//�ݹ飺ǰ�����������������ڵ��ֵ
void pre_traverse(treeNode* root) {
	//�˳�����
	if (root == NULL) {
		return;
	}
	cout << root->val << " ";
	pre_traverse(root->left);
	pre_traverse(root->right);
}

//�ǵݹ飺ǰ�����������������ڵ��ֵ
void preTraverse(treeNode* root) {

	stack<treeNode*> s;
	s.push(root);  //���ڵ���ջ
	while (!s.empty()) {
		treeNode* p = s.top();  //ȡջ��Ԫ�ص�ֵ
		s.pop();
		cout << p->val << " ";   //��������ڵ��ֵ

		if (p->right != NULL) {
			s.push(p->right);
		}
		if (p->left != NULL) {
			s.push(p->left);
		}
	}
}


//�ݹ飺�������������������ڵ��ֵ
void in_traverse(treeNode* root) {
	if (root == NULL) {
		return;
	}
	in_traverse(root->left);
	cout << root->val << " ";
	in_traverse(root->right);
}

//�ǵݹ飺�������������������ڵ��ֵ
void inTraverse(treeNode* root) {
	stack<treeNode*> s;
	s.push(root);

	while (!s.empty()) {
		treeNode* p = s.top();   //��ȡջ��Ԫ��ֵ�������ǳ�ջ

		if (p->left != NULL) {
			s.push(p->left);   //���ν�������
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


//�ݹ飺�������������������ڵ��ֵ
void post_traverse(treeNode* root) {
	if (root == NULL) {
		return;
	}
	post_traverse(root->left);
	post_traverse(root->right);
	cout << root->val << " ";
}

//�ǵݹ飺�������������������ڵ��ֵ
void postTraverse(treeNode* root) {
	stack<treeNode*> s;
	s.push(root);     //���ڵ���ջ

	treeNode* q = root;    //q�����ϴη��ʹ�(����ָ��ջ�����й����)�Ľڵ�
	treeNode* p = root;    //p�������

	while (p != NULL || !s.empty()) {
		p = s.top();

		while (p != NULL) {   //һֱ�ߵ�����Ϊ�գ�һֱ��ջ
			s.push(p);
			p = p->left;
		}

		p = s.top();  //�鿴��ǰջ��Ԫ��

		if (p->right == NULL || p->right == q) {  //�Һ���Ϊ�ջ��ѷ��ʹ��������������ڵ�
			cout << p->val << " ";
			s.pop();
			q = p;
			p = NULL;    //��ע������һ��Ҫ�������ڵ��ÿգ���Ϊ��ǰ�ڵ�����Һ��Ӷ��Ѿ���ջ�ˣ���ʹ�����
		}
		else {  //����Һ��Ӳ�Ϊ�����Һ���δ�����ʹ����Һ��ӽ�ջ
			//s.push(p->right);
			p = p->right;
		}
	}
}

/*
int main() {
	//����������
	vector<int> nums;
	int num;
	cout << "������������е�Ԫ�أ�������򣩣�" << endl;
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