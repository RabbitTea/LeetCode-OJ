package examination6;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		ArrayList<Integer> arr1 = new ArrayList<>();
		ArrayList<Integer> arr2 = new ArrayList<>();

		System.out.println("�������һ�ö�������Ԫ��ֵ��");
		Scanner sc1 = new Scanner(System.in);
		while(!sc1.hasNext("q")) {
			arr1.add(sc1.nextInt());
		}
		
		//����
		/*
		for(int i=0;i<arr1.size();i++) {
			System.out.println(arr1.get(i));
		}
		*/
		
		System.out.println("������ڶ��ö�������Ԫ��ֵ��");
		Scanner sc2 = new Scanner(System.in);
		while(!sc2.hasNext("q")) {
			arr2.add(sc2.nextInt());
		}
		
		// ����������
		BinaryTreeNode temp1 = new BinaryTreeNode();
		BinaryTreeNode t1 = temp1.createTree(arr1);
		BinaryTreeNode temp2 = new BinaryTreeNode();
		BinaryTreeNode t2 = temp2.createTree(arr2);
		
		// �ϲ�������
		BinaryTreeNode newTree = mergeTrees(t1, t2);
		
		// ���
		System.out.println("�ϲ���Ķ�����Ϊ��");
		newTree.levelTravel(newTree);
	}
	
	public static BinaryTreeNode mergeTrees(BinaryTreeNode t1, BinaryTreeNode t2) {
		 if(t1 == null) return t2;
		 if(t2 == null) return t1;
		 
		 // �ϲ���t1����
		 BinaryTreeNode root = t1;
		 root.value += t2.value;   // ������ͬʱ���ڵĽڵ�ֵ���
		 // �ݹ�ϲ�������
		 root.leftchild = mergeTrees(t1.leftchild, t2.leftchild);
		 root.rightchild = mergeTrees(t1.rightchild, t2.rightchild);
		 
		 return root;
	}

}
