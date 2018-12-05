/*
 * �������Ľڵ���
 */
package examination7;

import java.util.ArrayDeque;
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
