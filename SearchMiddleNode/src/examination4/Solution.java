/*
 * @idea: 设置两个指针，一个一次走两步，一个一次走一步，当快指针走到最后一个节点时，慢指针刚好走到中间位置
 * @author: SA18225018
 * @date: 2018/11/14
 */
package examination4;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<>();
		System.out.println("请输入单链表的元素值：");
		
		//建立数组
		Scanner sc = new Scanner(System.in);
		while(!sc.hasNext("q")) {  //输入q结束
			arr.add(sc.nextInt());
		}
		
		//建立单链表
		ListNode head = new ListNode(0);
		head = head.create(head, arr);   
		
		//寻找中间节点
		ListNode middle = Solution.findMiddleNode(head);
		
		//输出
		System.out.println("The middle node's value = " + middle.val);
        ListNode p = middle;
        System.out.print("后续节点的值为：[");
        while(p.next != null) {
        	System.out.print(p.val + ",");
        	p = p.next;
        }
        System.out.println(p.val + "]");
	}

	public static ListNode findMiddleNode(ListNode head) {
		ListNode slow = head, fast = head;
		
		while(fast != null && fast.next != null) {
			fast = fast.next.next;
			slow = slow.next;
		}
		
		return slow;
	}
}
