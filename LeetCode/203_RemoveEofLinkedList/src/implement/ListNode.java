/*
 * @description  ����ڵ���
 */
package implement;

import java.util.ArrayList;

public class ListNode {
	int data;   //������
	ListNode next;  //ָ����
	
	//���캯��
	ListNode(int val){
		data = val;
		next = null;
	}
	
	// β�巨����һ��������
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
