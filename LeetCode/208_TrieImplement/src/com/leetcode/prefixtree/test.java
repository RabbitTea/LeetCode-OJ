package com.leetcode.prefixtree;

import java.util.Scanner;

public class test {

	public static void main(String[] args) {
		//测试字典树
		Trie trie = new Trie();
		
		//插入单词
		System.out.println("请输入要插入的单词：");
		Scanner sc = new Scanner(System.in);
		String wordIn = sc.nextLine();
		trie.insert(wordIn);
		
		//查询单词
		System.out.println("请输入要查询的单词：");
		Scanner query = new Scanner(System.in);
		String wordFind = query.nextLine();
		trie.search(wordFind);
		
		//前缀匹配
		System.out.println("请输入要匹配的前缀：");
		Scanner in = new Scanner(System.in);
		String prefix = in.nextLine();
		trie.startsWith(prefix);
	}

}
