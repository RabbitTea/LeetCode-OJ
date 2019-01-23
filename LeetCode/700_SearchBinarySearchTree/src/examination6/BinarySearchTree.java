package examination6;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class BinarySearchTree {
	public int value;
	public BinarySearchTree leftchild;
	public BinarySearchTree rightchild;
	
	BinarySearchTree(int val) {
		this.value = val;
		this.leftchild = null;
		this.rightchild = null;
	}
	
	BinarySearchTree(){}
	
	/*
	// �������������
	public BinarySearchTree createSearchTree(ArrayList<Integer> arr) {
		List<BinarySearchTree> nodelist = new ArrayList<>(); // ���нڵ��б�
		
		// ���������е�ֵ�����δ������еĽڵ�
		for(int i=0;i<arr.size();i++) {
			BinarySearchTree treeNode = new BinarySearchTree(arr.get(i));
			nodelist.add(treeNode);
			//System.out.println(nodelist.get(i).value);
		}
		
		BinarySearchTree p = nodelist.get(0); // p��ʼָ����ڵ�
		for(int i=1;i<nodelist.size();i++) {
		 while(p != null) {
			if(nodelist.get(i).value < p.value) {   // ���ڵ����Ľڵ�ֵС�ڸ��ڵ�ֵ
				if(p.leftchild != null) p = p.leftchild;
				else
					p.leftchild = nodelist.get(i);
				    break;
			}
				
			if(nodelist.get(i).value > p.value) {   // ���ڵ��Ҳ�Ľڵ�ֵ���ڸ��ڵ�ֵ
				if(p.rightchild != null) p =p.rightchild;
				else
					p.rightchild = nodelist.get(i);
				    break;
			}
		 }
		}
		
		BinarySearchTree root = nodelist.get(0);
		return root;
	}
	*/
	public BinarySearchTree createTree(ArrayList<Integer> arr) {
		BinarySearchTree root = null;
		// ���÷��Ͷ�̬�����Ŷ������ĸ����ڵ�
		List<BinarySearchTree> nodelist = new ArrayList<BinarySearchTree>();
		
		// ѭ�������ڵ㣬����ӵ�nodelist��
		for(int i=0;i<arr.size();i++) {
			nodelist.add(new BinarySearchTree(arr.get(i)));
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
	
	
	// ��������������������
	public void levelTralPrint(BinarySearchTree root) {
		if(root == null) return;
		
		// ���ö������ݽṹ
		Queue<BinarySearchTree> queue = new ArrayDeque<BinarySearchTree>();
		//���ڵ����
		queue.add(root);
		
		// ���������
		BinarySearchTree current = new BinarySearchTree();
		while(!queue.isEmpty()) {
			current = queue.poll(); // currentΪ����ͷ�ڵ�
			System.out.print(current.value + " ");
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
		
		BinarySearchTree temp = new BinarySearchTree();
		BinarySearchTree root = temp.createTree(arr);
		temp.levelTralPrint(root);
	}
}
