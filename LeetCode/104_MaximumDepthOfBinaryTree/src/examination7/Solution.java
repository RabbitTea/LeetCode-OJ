/*
 * @description������һ�ö��������������������ȣ�����Ϊ���ڵ㵽Ҷ�ӽڵ���·���ϵ����ڵ���[�������ڵ�]��
 * @idea���ݹ��˼�롪���ֱ��������������м�����ȣ����ѡȡ���ߵ����ֵ�����������һ�����ڵ㣩
 */
package examination7;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<>();
		
		// ��ȡ����
		System.out.println("�����������Ԫ�أ�");
		Scanner sc = new Scanner(System.in);
		while(!sc.hasNext("q")) {
			arr.add(sc.nextInt());
		}
		
		// ������򴴽�������
		TreeNode tmp = new TreeNode();
		TreeNode root = tmp.createTree(arr);
		
		// �ҵ�������
		int maxd = maxDepth(root);
		
		// ���
		System.out.println("�ö�������������Ϊ��" + maxd);
	}
	
	public static int maxDepth(TreeNode root) {
		// �ݹ��˳�����
		if(root == null) {
			return 0;
		}
		
		/*
		 * �ݹ鴦��ʵ���ϵݹ鵽Ҷ�ڵ㣬ͳ������ڵ����Ϊ1�����Ϸ������丸�ף���������ӷ��ص�����
		 *        �����ݹ鵽�Һ��ӣ�������Һ��ӷ��ص������ø��׵���ȣ������Ϸ������������ơ�
		 */
		int left = maxDepth(root.leftchild);
		int right = maxDepth(root.rightchild);
		return Math.max(left, right) + 1;
	}

}
