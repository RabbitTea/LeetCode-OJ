package examination6;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class BinaryTreeNode {
	public int value;    // �ڵ��ֵ
	public BinaryTreeNode leftchild;  // ����
	public BinaryTreeNode rightchild;  // �Һ���
	
	// ���캯��
	BinaryTreeNode(int val){
		this.value = val;
		this.leftchild = null;
		this.rightchild = null;
	}
	
	BinaryTreeNode() {
		
	}
	
	// ������򴴽�������
	public BinaryTreeNode createTree(ArrayList<Integer> arr) {
		BinaryTreeNode root = null;
		// ���÷��Ͷ�̬�����Ŷ������ĸ����ڵ�
		List<BinaryTreeNode> nodelist = new ArrayList<BinaryTreeNode>();
		
		// ѭ�������ڵ㣬����ӵ�nodelist��
		for(int i=0;i<arr.size();i++) {
			nodelist.add(new BinaryTreeNode(arr.get(i)));
		}
		
		// ��n/2-1�����ڵ㽨�����ӹ�ϵ
		for(int i=0;i<arr.size()/2-1;i++) {
			nodelist.get(i).leftchild = nodelist.get(2*i+1);  // ����
			nodelist.get(i).rightchild = nodelist.get(2*i+2); // �Һ���
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
	public void levelTravel(BinaryTreeNode root) {
		if(root == null)
			return;
		
		// ����Java���ö���
		Queue<BinaryTreeNode> queue = new ArrayDeque<BinaryTreeNode>();
		queue.add(root); // ͷ�ڵ����
		
		BinaryTreeNode current = null;
		while(!queue.isEmpty()) {
			current = queue.poll();  // ��ǰ�Ķ���ͷ����ʼΪ���ڵ�
			System.out.print(current.value + " "); // ����һ���ڵ��ʹ�������Һ��ӽ���
			if(current.leftchild != null)
				queue.add(current.leftchild);
			if(current.rightchild != null)
				queue.add(current.rightchild);
		}
	}
	
	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<>();
		arr.add(4);
		arr.add(2);
		arr.add(7);
		arr.add(1);
		arr.add(3);
		
		BinaryTreeNode tree = new BinaryTreeNode();
		BinaryTreeNode root = tree.createTree(arr);
		//System.out.println(root.value + " " + root.leftchild.value);
		root.levelTravel(root);
	}
}
