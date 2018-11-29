package examination6;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<>();
		System.out.println("����������������");
		
        Scanner sc = new Scanner(System.in);
        while(!sc.hasNext("q")) {
        	arr.add(sc.nextInt());
        }
        /*
        //����4
        for(int i=0;i<arr.size();i++) {
        	System.out.println(arr.get(i));
        }
        */
        
        // �������������
        BinarySearchTree temp = new BinarySearchTree();
        BinarySearchTree root = temp.createTree(arr);
        
        System.out.println("��������ҵ�ֵ��");
        int val;
        Scanner number = new Scanner(System.in);
        val = number.nextInt();
        
        // ���Ҷ�Ӧֵ�Ľڵ�
        BinarySearchTree subNode = searchSubtree(root, val);
        
        // �������
        if(subNode == null)
        	System.out.println("The subtree is null!");
        else {
        	BinarySearchTree bt = new BinarySearchTree();
        	System.out.println("�Ը�ֵΪ��������Ϊ��");
        	bt.levelTralPrint(subNode);
        }
	}
    
	public static BinarySearchTree searchSubtree(BinarySearchTree root, int val) {
		BinarySearchTree p = root;
		BinarySearchTree subNode = null;  // ����ֵ��ͬ�Ľڵ�
		while(p != null) {
			if(p.value == val) {
				subNode = p;
				break;
			}
			if(val < p.value) {
				if(p.leftchild != null)
					p = p.leftchild;
				else
					subNode = null;
			}
			if(val > p.value) {
				if(p.rightchild != null)
					p = p.rightchild;
				else
					subNode = null;
			}
		}
		
		return subNode;
	}
}
