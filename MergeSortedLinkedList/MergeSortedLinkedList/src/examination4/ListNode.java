package examination4;

import java.util.ArrayList;

public class ListNode {
	public int val;
	public ListNode next;
	
	//构造函数
	ListNode(int val){
		this.val = val;
		next = null;
	}
	
	//尾插法建立单链表
	public ListNode create(ListNode head, ArrayList<Integer> arr) {

		ListNode p = head;
		
		for(int i=0;i<arr.size();i++) {
			ListNode newNode = new ListNode(arr.get(i));
			p.next = newNode;
			p = p.next;
		}
		
		return head.next;
	}
}
