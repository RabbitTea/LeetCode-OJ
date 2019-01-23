package examination7;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class TreeNode {
	public int value;    // �ڵ��ֵ
	public TreeNode leftchild;  // ����
	public TreeNode rightchild;  // �Һ���
	
	// ���캯��
	TreeNode(int val){
		this.value = val;
		this.leftchild = null;
		this.rightchild = null;
	}
	
	TreeNode() {
		
	}
	
	// ������򴴽�������
	public TreeNode createTree(ArrayList<Integer> arr) {
		TreeNode root = null;
		// ���÷��Ͷ�̬�����Ŷ������ĸ����ڵ�
		List<TreeNode> nodelist = new ArrayList<TreeNode>();
		
		// ѭ�������ڵ㣬����ӵ�nodelist��
		for(int i=0;i<arr.size();i++) {
			nodelist.add(new TreeNode(arr.get(i)));
		}
		
		// ��n/2-1�����ڵ㽨�����ӹ�ϵ
		for(int i=0;i<arr.size()/2-1;i++) {
			// ����Ϊ0ֵ��ʾ�ýڵ�Ϊ�սڵ�
			if(arr.get(2*i+1) == 0) {
				nodelist.get(i).leftchild = null;
			}
			else if(arr.get(2*i + 2) == 0) {
				nodelist.get(i).rightchild = null;
			}
			else {
				nodelist.get(i).leftchild = nodelist.get(2*i+1);  // ����
				nodelist.get(i).rightchild = nodelist.get(2*i+2); // �Һ���
			}	
		}
		
		// ���һ�����ڵ�,�����鳤��Ϊ����ʱ�����Һ���
		int lastParentIndex = arr.size() / 2 - 1;
		nodelist.get(lastParentIndex).leftchild = nodelist.get(2*lastParentIndex+1);
		if(arr.size() % 2 == 1) {
			nodelist.get(lastParentIndex).rightchild = nodelist.get(2*lastParentIndex+2);
		}
		
		root = nodelist.get(0); // ָ�����ڵ�
		return root;
	}
	
	// �����������������:��Ҫ�õ����У����ù������������˼��
	public void levelTravel(TreeNode root) {
		if(root == null)
			return;
		
		// ����Java���ö���
		Queue<TreeNode> queue = new ArrayDeque<TreeNode>();
		queue.add(root); // ͷ�ڵ����
		
		TreeNode current = null;
		while(!queue.isEmpty()) {
			current = queue.poll();  // ��ǰ�Ķ���ͷ����ʼΪ���ڵ�
			System.out.print(current.value + " "); // ����һ���ڵ��ʹ�������Һ��ӽ���
			if(current.leftchild != null)
				queue.add(current.leftchild);
			if(current.rightchild != null)
				queue.add(current.rightchild);
		}
	}
}
