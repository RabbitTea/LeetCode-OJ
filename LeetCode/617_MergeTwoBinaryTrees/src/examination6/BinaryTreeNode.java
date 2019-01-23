package examination6;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class BinaryTreeNode {
	public int value;    // 节点的值
	public BinaryTreeNode leftchild;  // 左孩子
	public BinaryTreeNode rightchild;  // 右孩子
	
	// 构造函数
	BinaryTreeNode(int val){
		this.value = val;
		this.leftchild = null;
		this.rightchild = null;
	}
	
	BinaryTreeNode() {
		
	}
	
	// 按层次序创建二叉树
	public BinaryTreeNode createTree(ArrayList<Integer> arr) {
		BinaryTreeNode root = null;
		// 利用泛型动态数组存放二叉树的各个节点
		List<BinaryTreeNode> nodelist = new ArrayList<BinaryTreeNode>();
		
		// 循环创建节点，并添加到nodelist中
		for(int i=0;i<arr.size();i++) {
			nodelist.add(new BinaryTreeNode(arr.get(i)));
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
	
	// 层次序遍历输出二叉树:需要用到队列；利用广度优先搜索的思想
	public void levelTravel(BinaryTreeNode root) {
		if(root == null)
			return;
		
		// 创建Java内置队列
		Queue<BinaryTreeNode> queue = new ArrayDeque<BinaryTreeNode>();
		queue.add(root); // 头节点进队
		
		BinaryTreeNode current = null;
		while(!queue.isEmpty()) {
			current = queue.poll();  // 当前的队列头；初始为根节点
			System.out.print(current.value + " "); // 访问一个节点后，使它的左右孩子进队
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
