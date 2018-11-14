/*
 * @idea: ��������ָ�룬һ��һ����������һ��һ����һ��������ָ���ߵ����һ���ڵ�ʱ����ָ��պ��ߵ��м�λ��
 * @author: SA18225018
 * @date: 2018/11/14
 */
package examination4;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<>();
		System.out.println("�����뵥�����Ԫ��ֵ��");
		
		//��������
		Scanner sc = new Scanner(System.in);
		while(!sc.hasNext("q")) {  //����q����
			arr.add(sc.nextInt());
		}
		
		//����������
		ListNode head = new ListNode(0);
		head = head.create(head, arr);   
		
		//Ѱ���м�ڵ�
		ListNode middle = Solution.findMiddleNode(head);
		
		//���
		System.out.println("The middle node's value = " + middle.val);
        ListNode p = middle;
        System.out.print("�����ڵ��ֵΪ��[");
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
