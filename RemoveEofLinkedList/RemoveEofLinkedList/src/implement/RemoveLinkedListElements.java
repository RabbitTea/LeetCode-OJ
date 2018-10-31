/**
 * @description  ����һ�����͵������һ��intֵ��ɾ�����������������������ֵ��ͬ�Ľڵ㣬�������޸ĺ�ĵ�����
 * @idea  �ؼ��������ֵ��ͷ�ڵ��е�Ԫ��ֵ��ͬ���������Ҫ����һ����ʼΪ�յĽڵ㣬����ָ����ָ��õ������ͷ�ڵ�
 * @author  SA18225018
 * @date   2018/10/31
 */
package implement;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class RemoveLinkedListElements {

	public static void main(String[] args) {
		//  ���Ժ���
		System.out.println("�����뵥�����е�Ԫ��ֵ��");
		Scanner sc = new Scanner(System.in); // ����һ��Scanner�����ȡ����̨Ԫ���б������
		
		ArrayList<Integer> arr = new ArrayList<>(); // ����һ����̬����
		
		while(!sc.hasNext("q")) {  // ���뵥�����Ԫ��ֵ���������ַ�q���˳�
			arr.add(Integer.valueOf(sc.next()));  //  ��Ԫ��ֵ��ӵ���̬������
		}
		
		ListNode head = new ListNode(arr.get(0));  // ���������еĵ�һ��Ԫ�ش���һ��ͷ�ڵ�
		head.creat(head, arr);  // ����β�巨����������
		
		Scanner sc2 = new Scanner(System.in);  // ����һ���µ�Scanner�����ȡ����̨��Ҫɾ��Ԫ�ص�����
		System.out.println("������Ҫɾ����Ԫ��ֵ��");
		int val = sc2.nextInt();
		
		RemoveLinkedListElements re = new RemoveLinkedListElements();
	    re.removeAllElements(head, val);  // ����ɾ��������ͬԪ�صķ���
	    System.out.println("ɾ����Ԫ�غ������Ϊ��");
	    while(head != null) {
	    	System.out.print(head.data + " ");
	    	head = head.next;
	    }
	    System.out.println();
		
	}

	public ListNode removeAllElements(ListNode head, int val)
	{
		// ����һ���սڵ㣬ʹ��ָ�������ͷ�ڵ�
		ListNode root = new ListNode(0);
		root.next = head;
		
		// ����һ���սڵ㣬����ָ��ǰ�����ڵ��ǰ���������ɾ��������Ҫ����ýڵ��ǰ���ڵ㣩
        ListNode prev = root;  //prev�ڵ��ʼ��Ϊͷ�ڵ��ǰ��	
        
		while(prev.next != null) {
			if(prev.next.data == val) {
				ListNode x = prev.next; //x����Ҫɾ���Ľڵ�
				prev.next = x.next;  // �Խڵ����ɾ������
			}
			else {
				prev = prev.next; // ֵ��ƥ����prev�ڵ����
			}
		}
		
		return root.next;  // ע��һ��Ҫ�����µĸ��ڵ㣨��ֹ����ͷ�ڵ�head��ɾ���������
	}
}
