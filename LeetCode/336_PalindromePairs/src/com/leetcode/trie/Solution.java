package com.leetcode.trie;
/*
 * @description������Ϊ����һ���������飬�ҵ��������������Ӧ�ĵ�����ƴ�ӳɻ��Ĵ���
 * @idea���ο������ϵ������뷨��
 *       1.�������ݽṹ�����⣻
 *         1.1 �����ĵ�������ʹ��ʲô�洢��
 *         �� �����õ��˾���ĵ��ʣ������Ҫ�ҵ������ǵ����������뵽map�ṹ�����Դ洢��ֵ�ԣ���������˵����Ψһ�����Ծ���ĵ�����Ϊ����������Ϊֵ��
 *         1.2 �����ʲô�洢��
 *         �� ��Ҫ�����ɻ��Ĵ�����������ֵ�������һ�����飬�����������ж���������Ƕ�̬�Ķ�ά���飻
 *         �� ��Ŀ�и����ķ���ֵ��List<List<Integer>>���ͣ���Ϊ�˱����ظ������ǿ�������Set<List<Integer>>���洢�������ת����
 *       2.�����������ÿ�����ⶼҪ���ǵ������������
 *         2.1 ��ǰ���ʱ���Ϊ���ģ���words�д��ڿմ�
 *         2.2 ��ǰ���ʵ����򴮴�����������
 *         2.3 ����ǰ���ʰ�����������˳�����β��Ϊ����������left��right
 *             2.3.1 ��leftΪ���ģ���right��������words��
 *             2.3.2 ��rightΪ���ģ���left��������words��
 *             �� ע����������������������˳��
 *       3.�����Ļ�������
 *       �� �ж�һ���ַ����Ƿ��ǻ��Ĵ�
 *@author��RabbitTea
 *@date��2019/2/16
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Solution {
	
	public List<List<Integer>> palindromePairs(String[] words){
		Map<String,Integer> trieWords = new HashMap<String,Integer>();   //�洢��������
		Set<List<Integer>> res = new HashSet<>();   // �ݴ�������֤Ψһ
		
		int i = 0;  //����i��Ϊ�˰�����Ԫ����������ѭ��ʱ���Կ����ṩ����ֵ������ѭ����i�����ķ�ʽ��
		for(String word:words) {
			trieWords.put(word, i++);    //������������ӵ�map�ṹ
		}
		
		i = 0;   //����iΪ0��������һ��ѭ��
		for(String word:words) {
			int len = word.length();
			for(int index=0;index<len;index++) {  //������������������
				String left = word.substring(0, index);   //substringȡ����һ��������ǰһλ
				String right = word.substring(index,len);
				
				 if(isPalindrome(word) && trieWords.get("") != null){
	                    List<Integer> list1 = new ArrayList<>();
	                    list1.add(i);
	                    list1.add(trieWords.get(""));
	                    res.add(list1);
	                    
	                    List<Integer> list2 = new ArrayList<>();
	                    list2.add(trieWords.get(""));
	                    list2.add(i);
	                    res.add(list2);
	                    break;
	                }
				
				if(isPalindrome(left)) {
					Integer temp = trieWords.get(new StringBuilder(right).reverse().toString());  //��ȡright�ַ������򴮵�����ֵ
					if(temp != null && temp != i) {
						List<Integer> list = new ArrayList<>();
						list.add(temp);
						list.add(i);
						res.add(list);
					}
				}
				
				if(isPalindrome(right)) {
					Integer temp = trieWords.get(new StringBuilder(left).reverse().toString());
					if(temp != null && temp != i) {
						List<Integer> list = new ArrayList<>();
						list.add(i);
						list.add(temp);
						res.add(list);
					}
				}
			}
			i++;
		}
		
		List<List<Integer>> result = new ArrayList<>(res);
		return result;
	}

	public boolean isPalindrome(String word) {
		int left = 0;
		int right = word.length()-1;
		while(left <= right) {
			if(word.charAt(left) == word.charAt(right)) {
				left++;
				right--;
			}else
				return false;
		}
		
		return true;
	}
}
