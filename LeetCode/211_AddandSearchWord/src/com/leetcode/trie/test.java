package com.leetcode.trie;

import java.util.Scanner;

public class test {

	public static void main(String[] args) {
		System.out.println("请输入要添加的单词：");
		Scanner sc = new Scanner(System.in);
		
		WordDictionary wd = new WordDictionary();
		
		//添加单词
		String word = sc.next();
		wd.addWord(word);
		
		System.out.println("请输入要查找的单词：");
		Scanner find = new Scanner(System.in);
		
		//查找单词
		String fword = find.next();
		wd.search(fword);
	}

}
