package examination5;

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
		
        //�ع�������
		ListNode newhead = oddEvenList(head);
		
		//���
		System.out.println("�ع���ĵ�����Ϊ��");
		ListNode p = newhead;
		while(p != null) {
			System.out.print(p.val + " ");
			p = p.next;
		}
	}

	public static ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) 
        	return head;
        
        ListNode even = head.next;  // ����ż�������ͷ�ڵ㣬�������ʱ��
        ListNode oddNext = head;    // �����ڵ��ͷ
        ListNode evenNext = even;  // ż���ڵ��ͷ
        
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
