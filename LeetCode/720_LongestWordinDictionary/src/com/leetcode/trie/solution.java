package com.leetcode.trie;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

import com.leetcode.trie.Trie.TrieNode;

/*
 * @description：给定一个字符串数组，找出其中最长且能被其它单词依次得到的字符串(实质为前缀匹配)，若得到多个，则返回字典序较小的那个单词；
 * @idea：1.利用Trie树提高查找效率，减少字符串的匹配；
 *       2.结合深度优先搜索进行查找。
 * @author：Sandra
 * @date：2019/1/25
 */

public class solution {

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
		
		/*
		//排序字符串数组
		Collections.sort(Arrays.asList(words));
		//Arrays.sort(words);
		*/
		
		//将词典构建为Trie树
		Trie trie = new Trie();
		int index = 0;
		for(String word : words) {
			trie.insert(word,++index);
		}
		String longWord = trie.dfs(words);
		
		return longWord;
	}
}
