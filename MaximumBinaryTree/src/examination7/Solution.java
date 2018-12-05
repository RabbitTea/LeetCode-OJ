/*
 * @description：给定一个无序的整型数组，创建一个最大二叉树（类似最大堆）
 * @idea：数组中最大值为整棵树的根节点，其分隔出的左右两部分（在数组中的位置）再分别创建最大二叉树，
 *       成为其父节点的左右子树（对应）；
 *       采用分治思想：先遍历数组找到最大值，创建一个节点，分别在左右子数组上(使用两个变量指定子数组的范围)调用递归，将结果连接到该节点上。
 * @author：SA18225018
 * @date：2018/12/4
 */
package examination7;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
	
	public static void main(String[] args) {
		ArrayList<Integer> nums = new ArrayList<>();
		// 获取输入
		System.out.println("请输入数组元素：");
		Scanner sc = new Scanner(System.in);
		while(!sc.hasNext("q")) {
			nums.add(sc.nextInt());
		}
		
		// 构建最大二叉树
		TreeNode maxTree = constructMaximumTree(nums);
		
		// 按层次序输出构建的二叉树
		TreeNode tmp = new TreeNode();
		tmp.levelTravel(maxTree);
	}
	
	public static TreeNode constructMaximumTree(ArrayList<Integer> nums){
		if(nums.isEmpty()) return null;
		return helper(nums, 0, nums.size()-1);
	}
	
	// 递归处理
	public static TreeNode helper(ArrayList<Integer> nums, int left, int right) {
		if(left > right) return null;  // 递归退出条件
		
		int mid = left; // mid保存当前处理数组的最大值的索引，初始为数组的开头位置
		//找到当前数组的最大值所在索引
		for(int i=left+1;i<=right;++i) {
			if(nums.get(i) > nums.get(mid)) {
				mid = i;
			}
		}
		// 建立根节点
		TreeNode node = new TreeNode(nums.get(mid));
		
		// 递归处理左右子数组
		node.leftchild = helper(nums, left, mid-1);
		node.rightchild = helper(nums, mid+1, right);
		
		return node;
	}
}
