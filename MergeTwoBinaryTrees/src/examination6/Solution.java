package examination6;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		ArrayList<Integer> arr1 = new ArrayList<>();
		ArrayList<Integer> arr2 = new ArrayList<>();

		System.out.println("请输入第一棵二叉树的元素值：");
		Scanner sc1 = new Scanner(System.in);
		while(!sc1.hasNext("q")) {
			arr1.add(sc1.nextInt());
		}
		
		//测试
		/*
		for(int i=0;i<arr1.size();i++) {
			System.out.println(arr1.get(i));
		}
		*/
		
		System.out.println("请输入第二棵二叉树的元素值：");
		Scanner sc2 = new Scanner(System.in);
		while(!sc2.hasNext("q")) {
			arr2.add(sc2.nextInt());
		}
		
		// 构建二叉树
		BinaryTreeNode temp1 = new BinaryTreeNode();
		BinaryTreeNode t1 = temp1.createTree(arr1);
		BinaryTreeNode temp2 = new BinaryTreeNode();
		BinaryTreeNode t2 = temp2.createTree(arr2);
		
		// 合并二叉树
		BinaryTreeNode newTree = mergeTrees(t1, t2);
		
		// 输出
		System.out.println("合并后的二叉树为：");
		newTree.levelTravel(newTree);
	}
	
	public static BinaryTreeNode mergeTrees(BinaryTreeNode t1, BinaryTreeNode t2) {
		 if(t1 == null) return t2;
		 if(t2 == null) return t1;
		 
		 // 合并到t1树上
		 BinaryTreeNode root = t1;
		 root.value += t2.value;   // 两棵树同时存在的节点值相加
		 // 递归合并二叉树
		 root.leftchild = mergeTrees(t1.leftchild, t2.leftchild);
		 root.rightchild = mergeTrees(t1.rightchild, t2.rightchild);
		 
		 return root;
	}

}
