/*
 * @description  链表节点类
 */
package implement;

import java.util.ArrayList;

public class ListNode {
	int data;   //数据域
	ListNode next;  //指针域
	
	//构造函数
	ListNode(int val){
		data = val;
		next = null;
	}
	
	// 尾插法创建一个单链表
	public ListNode creat(ListNode head, ArrayList<Integer> values){
		ListNode prev = head;
	    
		for(int i=1;i<values.size();i++) {
			ListNode newNode = new ListNode(values.get(i));
			prev.next = newNode;
			prev = prev.next;
		}
		return head;
	}
	
	/*
	public static void main(String[] args) {
		int[] arr = {1, 2, 6, 3, 4, 5, 6};
		ListNode head = new ListNode(arr[0]);
		
		head.creat(head, arr);
		
		while(head != null){
			System.out.println(head.data + " ");
			head = head.next;
		}
	}
	*/
}
