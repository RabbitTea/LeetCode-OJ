package com.leetcode.trie;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/*
 * @idea：由短到长排序字符串数组，利用集合存储合适的单词；
 *       选择长度为1或去掉最后一个字母后在集合中已经存在的单词加入集合(此时其之前所有的中间情况都会存在);
 *       初始化结果字符串为空，每次判断当前单词长度是否大于结果字符串的长度，若大于则更新结果。
 */

public class solution2 {

	public static void main(String[] args) {
String[] words = new String[1000];
		
		System.out.println("请输入字符串数组，用逗号隔开");
		Scanner sc = new Scanner(System.in);
		//可输入多次测试用例，输入0结束
		while(!sc.hasNext("0")) {
			String input = sc.next();
			
			//按逗号分隔，保存为字符串数组
			words = input.split(",");
		   
			//得到最长字符串
			String longWord = longestWord(words);
			
			//输出
			System.out.println("最长可前缀匹配的字符串为："+longWord);
			
			System.out.println("请输入字符串数组，用逗号隔开");
		}

	}

	public static String longestWord(String[] words) {
		String ans = "";
		
		Arrays.sort(words);   //排序字符串数组
		
		ArrayList<String> result = new ArrayList();
		
		for(String word : words) {
			if(word.length() == 1 || result.contains(word.substring(0, word.length()-1))) {
				ans = (word.length() > ans.length())? word : ans;
				result.add(word);  //满足条件，加入集合
			}
		}
		return ans;
	}
}
