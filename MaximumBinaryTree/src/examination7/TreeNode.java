/*
 * 二叉树的节点类
 */
package examination7;

import java.util.ArrayDeque;
import java.util.Queue;

public class TreeNode {
	public int value;    // 节点的值
	public TreeNode leftchild;  // 左孩子
	public TreeNode rightchild;  // 右孩子
	
	// 构造函数
	TreeNode(int val){
		this.value = val;
		this.leftchild = null;
		this.rightchild = null;
	}
	
	TreeNode() {
		
	}
	
	// 层次序遍历输出二叉树:需要用到队列；利用广度优先搜索的思想
	public void levelTravel(TreeNode root) {
		if(root == null)
			return;
		
		// 创建Java内置队列
		Queue<TreeNode> queue = new ArrayDeque<TreeNode>();
		queue.add(root); // 头节点进队
		
		TreeNode current = null;
		while(!queue.isEmpty()) {
			current = queue.poll();  // 当前的队列头；初始为根节点
			System.out.print(current.value + " "); // 访问一个节点后，使它的左右孩子进队
			if(current.leftchild != null)
				queue.add(current.leftchild);
			if(current.rightchild != null)
				queue.add(current.rightchild);
		}
	}
}
