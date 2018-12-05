/*
 * @description：给定一棵二叉树，返回树的最大深度（定义为根节点到叶子节点的最长路径上的最大节点数[包括根节点]）
 * @idea：递归的思想——分别在其左右子树中计算深度，最后选取两者的最大值，并将结果加一（根节点）
 */
package examination7;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<>();
		
		// 获取输入
		System.out.println("请输入二叉树元素：");
		Scanner sc = new Scanner(System.in);
		while(!sc.hasNext("q")) {
			arr.add(sc.nextInt());
		}
		
		// 按层次序创建二叉树
		TreeNode tmp = new TreeNode();
		TreeNode root = tmp.createTree(arr);
		
		// 找到最大深度
		int maxd = maxDepth(root);
		
		// 输出
		System.out.println("该二叉树的最大深度为：" + maxd);
	}
	
	public static int maxDepth(TreeNode root) {
		// 递归退出条件
		if(root == null) {
			return 0;
		}
		
		/*
		 * 递归处理：实际上递归到叶节点，统计自身节点个数为1，向上反馈给其父亲；如果是左孩子返回的则父亲
		 *        继续递归到右孩子，如果是右孩子返回的则计算该父亲的深度；再向上反馈，依次类推。
		 */
		int left = maxDepth(root.leftchild);
		int right = maxDepth(root.rightchild);
		return Math.max(left, right) + 1;
	}

}
