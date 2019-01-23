package examination6;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<>();
		System.out.println("请输入二叉查找树：");
		
        Scanner sc = new Scanner(System.in);
        while(!sc.hasNext("q")) {
        	arr.add(sc.nextInt());
        }
        /*
        //测试4
        for(int i=0;i<arr.size();i++) {
        	System.out.println(arr.get(i));
        }
        */
        
        // 创建二叉查找树
        BinarySearchTree temp = new BinarySearchTree();
        BinarySearchTree root = temp.createTree(arr);
        
        System.out.println("请输入查找的值：");
        int val;
        Scanner number = new Scanner(System.in);
        val = number.nextInt();
        
        // 查找对应值的节点
        BinarySearchTree subNode = searchSubtree(root, val);
        
        // 输出子树
        if(subNode == null)
        	System.out.println("The subtree is null!");
        else {
        	BinarySearchTree bt = new BinarySearchTree();
        	System.out.println("以改值为根的子树为：");
        	bt.levelTralPrint(subNode);
        }
	}
    
	public static BinarySearchTree searchSubtree(BinarySearchTree root, int val) {
		BinarySearchTree p = root;
		BinarySearchTree subNode = null;  // 保存值相同的节点
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
