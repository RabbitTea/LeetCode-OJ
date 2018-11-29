package examination4;

import java.util.ArrayList;

public class ListNode {
	public int val;
	public ListNode next;
	
	//���캯��
	ListNode(int val){
		this.val = val;
		next = null;
	}
	
	//β�巨����������
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
