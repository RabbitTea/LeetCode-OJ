package examination5;

import java.util.ArrayList;
import java.util.Scanner;

import examination5.ListNode;

public class Solution {
	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<>();
		System.out.println("请输入单链表的元素值：");
		
		//建立数组
		Scanner sc = new Scanner(System.in);
		while(!sc.hasNext("q")) {  //输入q结束
			arr.add(sc.nextInt());
		}
		
		//建立无环的单链表
		ListNode head = new ListNode(0);
		head = head.create(head, arr); 
		
		//判断是否有环
		ListNode isCycle = getCycleNode(head);
		if(isCycle == null) {
			System.out.println("该链表不存在环");
		}
		else {
			System.out.println("该链表存在环，环起点为：" + isCycle.val);
		}
		
		//给链表增加环
		ListNode p = head;
		while(p.next != null) {
			p = p.next;
		}
		p.next = head.next.next;
		System.out.println();
		System.out.println("已给链表添加环");
		
		//接着判断是否有环
		ListNode startCycle = getCycleNode(head);
		if(startCycle == null) {
			System.out.println("该链表不存在环");
		}
		else {
			System.out.println("该链表存在环，环起点为：" + startCycle.val);
		}
	}
	
	public static ListNode getCycleNode(ListNode head) {
        if(head == null || head.next == null) {
           return null;
       }

       ListNode fast = head;
       ListNode slow = head;

       while(fast.next != null && fast.next.next != null) {
           fast = fast.next.next;
           slow = slow.next;
           if(fast == slow) {  // 链表存在环
               slow = head;   // 慢指针回到头节点，快指针仍然在重合节点
               while(slow != fast) {
                   fast = fast.next;
                   slow = slow.next;
               }
               return slow;  // 当这两个节点再次重合时为环七点
           }
       }

       return null;
   }
}
