/*
 * @idea: 注意一个链表走到最后时直接添加另一个链表剩下的全部元素即可
 * @author： SA18225018
 * @date： 2018/11/14
 */
package examination4;

import java.util.ArrayList;
import java.util.Scanner;

public class MergeTwoList {

	public static void main(String[] args) {
		ArrayList<Integer> arr1 = new ArrayList<>();
		ArrayList<Integer> arr2 = new ArrayList<>();
		
		System.out.println("请输入第一个单链表中的元素值：");
		Scanner l1 = new Scanner(System.in);
		while(!l1.hasNext("q")) {  // 输入单链表的元素值，在输入字符q后退出
			arr1.add(Integer.valueOf(l1.next()));  //  将元素值添加到动态数组中
		}
		//创建单链表1
		ListNode head1 = new ListNode(0);
		head1 = head1.create(head1, arr1);
		
		System.out.println("请输入第二个单链表中的元素值：");
		Scanner l2 = new Scanner(System.in);
		while(!l2.hasNext("q")) {  // 输入单链表的元素值，在输入字符q后退出
			arr2.add(Integer.valueOf(l2.next()));  
		}
		//创建单链表2
		ListNode head2 = new ListNode(0);
		head2 = head2.create(head2, arr2);
		
		//得到合并后的单链表
		ListNode newlist = MergeTwoList.MergeLists(head1, head2);
        
		//输出
		System.out.println("合并后的单链表为:");
		ListNode p = newlist;
		while(p != null){
			System.out.print(p.val + " ");
			p = p.next;
		}
	}
	
	public static ListNode MergeLists(ListNode l1, ListNode l2) {
		ListNode newhead = new ListNode(0); // 建立新链表的头节点
		ListNode p = newhead;
		
		while (l1 != null || l2 != null) {
			if(l1 !=null && l2 != null) {
				if(l1.val <= l2.val) {
					p.next = l1;
					l1 = l1.next;
				}else {
					p.next = l2;
					l2 = l2.next;
				}
				p = p.next;
			}else if(l1 == null) {
				p.next = l2;
				break;
			}else if(l2 == null) {
				p.next = l1;
				break;
			}
		}
		
		return newhead.next;
	}

}
