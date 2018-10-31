/**
 * @description  输入一个整型单链表和一个int值，删除单链表中所有数据域与该值相同的节点，并返回修改后的单链表
 * @idea  关键是输入的值和头节点中的元素值相同的情况，需要创建一个初始为空的节点，令其指针域指向该单链表的头节点
 * @author  SA18225018
 * @date   2018/10/31
 */
package implement;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class RemoveLinkedListElements {

	public static void main(String[] args) {
		//  测试函数
		System.out.println("请输入单链表中的元素值：");
		Scanner sc = new Scanner(System.in); // 创建一个Scanner对象获取控制台元素列表的输入
		
		ArrayList<Integer> arr = new ArrayList<>(); // 创建一个动态数组
		
		while(!sc.hasNext("q")) {  // 输入单链表的元素值，在输入字符q后退出
			arr.add(Integer.valueOf(sc.next()));  //  将元素值添加到动态数组中
		}
		
		ListNode head = new ListNode(arr.get(0));  // 根据数组中的第一个元素创建一个头节点
		head.creat(head, arr);  // 利用尾插法建立单链表
		
		Scanner sc2 = new Scanner(System.in);  // 创建一个新的Scanner对象获取控制台对要删除元素的输入
		System.out.println("请输入要删除的元素值：");
		int val = sc2.nextInt();
		
		RemoveLinkedListElements re = new RemoveLinkedListElements();
	    re.removeAllElements(head, val);  // 调用删除所有相同元素的方法
	    System.out.println("删除该元素后的链表为：");
	    while(head != null) {
	    	System.out.print(head.data + " ");
	    	head = head.next;
	    }
	    System.out.println();
		
	}

	public ListNode removeAllElements(ListNode head, int val)
	{
		// 创建一个空节点，使其指向单链表的头节点
		ListNode root = new ListNode(0);
		root.next = head;
		
		// 创建一个空节点，用于指向当前操作节点的前驱（链表的删除操作需要保存该节点的前驱节点）
        ListNode prev = root;  //prev节点初始化为头节点的前驱	
        
		while(prev.next != null) {
			if(prev.next.data == val) {
				ListNode x = prev.next; //x保存要删除的节点
				prev.next = x.next;  // 对节点进行删除操作
			}
			else {
				prev = prev.next; // 值不匹配则prev节点后移
			}
		}
		
		return root.next;  // 注意一定要返回新的根节点（防止出现头节点head被删除的情况）
	}
}
