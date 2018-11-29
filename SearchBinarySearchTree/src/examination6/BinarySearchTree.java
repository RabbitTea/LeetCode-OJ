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
	// 创建二叉查找树
	public BinarySearchTree createSearchTree(ArrayList<Integer> arr) {
		List<BinarySearchTree> nodelist = new ArrayList<>(); // 树中节点列表
		
		// 根据数组中的值，依次创建树中的节点
		for(int i=0;i<arr.size();i++) {
			BinarySearchTree treeNode = new BinarySearchTree(arr.get(i));
			nodelist.add(treeNode);
			//System.out.println(nodelist.get(i).value);
		}
		
		BinarySearchTree p = nodelist.get(0); // p初始指向根节点
		for(int i=1;i<nodelist.size();i++) {
		 while(p != null) {
			if(nodelist.get(i).value < p.value) {   // 根节点左侧的节点值小于根节点值
				if(p.leftchild != null) p = p.leftchild;
				else
					p.leftchild = nodelist.get(i);
				    break;
			}
				
			if(nodelist.get(i).value > p.value) {   // 根节点右侧的节点值大于根节点值
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
		// 利用泛型动态数组存放二叉树的各个节点
		List<BinarySearchTree> nodelist = new ArrayList<BinarySearchTree>();
		
		// 循环创建节点，并添加到nodelist中
		for(int i=0;i<arr.size();i++) {
			nodelist.add(new BinarySearchTree(arr.get(i)));
		}
		
		// 对n/2-1个父节点建立孩子关系
		for(int i=0;i<arr.size()/2-1;i++) {
			nodelist.get(i).leftchild = nodelist.get(2*i+1);  // 左孩子
			nodelist.get(i).rightchild = nodelist.get(2*i+2); // 右孩子
		}
		
		// 最后一个父节点,在数组长度为奇数时才有右孩子
		int lastParentIndex = arr.size() / 2 - 1;
		nodelist.get(lastParentIndex).leftchild = nodelist.get(2*lastParentIndex+1);
		if(arr.size() % 2 == 1) {
			nodelist.get(lastParentIndex).rightchild = nodelist.get(2*lastParentIndex+2);
		}
		
		root = nodelist.get(0); // 指明根节点
		return root;
	}
	
	
	// 层次序遍历输出二叉查找树
	public void levelTralPrint(BinarySearchTree root) {
		if(root == null) return;
		
		// 利用队列数据结构
		Queue<BinarySearchTree> queue = new ArrayDeque<BinarySearchTree>();
		//根节点进队
		queue.add(root);
		
		// 遍历和输出
		BinarySearchTree current = new BinarySearchTree();
		while(!queue.isEmpty()) {
			current = queue.poll(); // current为队列头节点
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
