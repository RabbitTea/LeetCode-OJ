package com.leetcode.trie;
/*
 * @description：题意为给定一个单词数组，找到两个索引，其对应的单词能拼接成回文串。
 * @idea：参考了网上的神仙想法；
 *       1.考虑数据结构的问题；
 *         1.1 给定的单词数组使用什么存储？
 *         — 解题用到了具体的单词，而输出要找的是它们的索引，则想到map结构，可以存储键值对，由于题意说单词唯一，所以具体的单词作为键，索引作为值；
 *         1.2 结果用什么存储？
 *         — 需要输出组成回文串的两个索引值，这就是一个数组，而这类数组有多个，所以是动态的二维数组；
 *         — 题目中给定的返回值是List<List<Integer>>类型，但为了避免重复，我们可以先用Set<List<Integer>>来存储结果，再转换。
 *       2.解决方法——每个问题都要考虑到几种特殊情况
 *         2.1 当前单词本身为回文，且words中存在空串
 *         2.2 当前单词的逆序串存在于数组中
 *         2.3 将当前单词按索引递增的顺序依次拆分为左右两部分left和right
 *             2.3.1 若left为回文，且right的逆序串在words中
 *             2.3.2 若right为回文，且left的逆序串在words中
 *             — 注意以上两种情况的索引组成顺序
 *       3.辅助的基本函数
 *       — 判断一个字符串是否是回文串
 *@author：RabbitTea
 *@date：2019/2/16
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Solution {
	
	public List<List<Integer>> palindromePairs(String[] words){
		Map<String,Integer> trieWords = new HashMap<String,Integer>();   //存储单词数组
		Set<List<Integer>> res = new HashSet<>();   // 暂存结果，保证唯一
		
		int i = 0;  //设置i是为了按单个元素在数组中循环时，仍可以提供索引值，按照循环中i递增的方式；
		for(String word:words) {
			trieWords.put(word, i++);    //将给定数组添加到map结构
		}
		
		i = 0;   //重置i为0以用于下一次循环
		for(String word:words) {
			int len = word.length();
			for(int index=0;index<len;index++) {  //按索引递增划分数组
				String left = word.substring(0, index);   //substring取到后一个参数的前一位
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
					Integer temp = trieWords.get(new StringBuilder(right).reverse().toString());  //获取right字符串逆序串的索引值
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
