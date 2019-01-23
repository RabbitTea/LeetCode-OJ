package examination5;

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
		
        //重构单链表
		ListNode newhead = oddEvenList(head);
		
		//输出
		System.out.println("重构后的单链表为：");
		ListNode p = newhead;
		while(p != null) {
			System.out.print(p.val + " ");
			p = p.next;
		}
	}

	public static ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) 
        	return head;
        
        ListNode even = head.next;  // 保存偶数链表的头节点，最后链接时用
        ListNode oddNext = head;    // 奇数节点的头
        ListNode evenNext = even;  // 偶数节点的头
        
        while (evenNext != null) {
            oddNext.next = evenNext.next;
            
            if (oddNext.next != null) {
                oddNext = oddNext.next;
                evenNext.next = oddNext.next;
                evenNext = evenNext.next;
            } else {
                break;
            }
        }
        oddNext.next = even;
        return head;
    }
}
