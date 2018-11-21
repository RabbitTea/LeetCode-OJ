package examination5;

import java.util.ArrayList;
import java.util.Scanner;

import examination5.ListNode;

public class Solution {
	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<>();
		System.out.println("�����뵥�����Ԫ��ֵ��");
		
		//��������
		Scanner sc = new Scanner(System.in);
		while(!sc.hasNext("q")) {  //����q����
			arr.add(sc.nextInt());
		}
		
		//�����޻��ĵ�����
		ListNode head = new ListNode(0);
		head = head.create(head, arr); 
		
		//�ж��Ƿ��л�
		ListNode isCycle = getCycleNode(head);
		if(isCycle == null) {
			System.out.println("���������ڻ�");
		}
		else {
			System.out.println("��������ڻ��������Ϊ��" + isCycle.val);
		}
		
		//���������ӻ�
		ListNode p = head;
		while(p.next != null) {
			p = p.next;
		}
		p.next = head.next.next;
		System.out.println();
		System.out.println("�Ѹ�������ӻ�");
		
		//�����ж��Ƿ��л�
		ListNode startCycle = getCycleNode(head);
		if(startCycle == null) {
			System.out.println("���������ڻ�");
		}
		else {
			System.out.println("��������ڻ��������Ϊ��" + startCycle.val);
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
           if(fast == slow) {  // ������ڻ�
               slow = head;   // ��ָ��ص�ͷ�ڵ㣬��ָ����Ȼ���غϽڵ�
               while(slow != fast) {
                   fast = fast.next;
                   slow = slow.next;
               }
               return slow;  // ���������ڵ��ٴ��غ�ʱΪ���ߵ�
           }
       }

       return null;
   }
}
