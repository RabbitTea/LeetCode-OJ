/*
 * @description������һ��������������飬����һ�������������������ѣ�
 * @idea�����������ֵΪ�������ĸ��ڵ㣬��ָ��������������֣��������е�λ�ã��ٷֱ𴴽�����������
 *       ��Ϊ�丸�ڵ��������������Ӧ����
 *       ���÷���˼�룺�ȱ��������ҵ����ֵ������һ���ڵ㣬�ֱ���������������(ʹ����������ָ��������ķ�Χ)���õݹ飬��������ӵ��ýڵ��ϡ�
 * @author��SA18225018
 * @date��2018/12/4
 */
package examination7;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
	
	public static void main(String[] args) {
		ArrayList<Integer> nums = new ArrayList<>();
		// ��ȡ����
		System.out.println("����������Ԫ�أ�");
		Scanner sc = new Scanner(System.in);
		while(!sc.hasNext("q")) {
			nums.add(sc.nextInt());
		}
		
		// ������������
		TreeNode maxTree = constructMaximumTree(nums);
		
		// ���������������Ķ�����
		TreeNode tmp = new TreeNode();
		tmp.levelTravel(maxTree);
	}
	
	public static TreeNode constructMaximumTree(ArrayList<Integer> nums){
		if(nums.isEmpty()) return null;
		return helper(nums, 0, nums.size()-1);
	}
	
	// �ݹ鴦��
	public static TreeNode helper(ArrayList<Integer> nums, int left, int right) {
		if(left > right) return null;  // �ݹ��˳�����
		
		int mid = left; // mid���浱ǰ������������ֵ����������ʼΪ����Ŀ�ͷλ��
		//�ҵ���ǰ��������ֵ��������
		for(int i=left+1;i<=right;++i) {
			if(nums.get(i) > nums.get(mid)) {
				mid = i;
			}
		}
		// �������ڵ�
		TreeNode node = new TreeNode(nums.get(mid));
		
		// �ݹ鴦������������
		node.leftchild = helper(nums, left, mid-1);
		node.rightchild = helper(nums, mid+1, right);
		
		return node;
	}
}
