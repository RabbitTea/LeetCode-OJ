package com.leetcode.trie;

import java.util.Scanner;

public class test {

	public static void main(String[] args) {
		System.out.println("������Ҫ��ӵĵ��ʣ�");
		Scanner sc = new Scanner(System.in);
		
		WordDictionary wd = new WordDictionary();
		
		//��ӵ���
		String word = sc.next();
		wd.addWord(word);
		
		System.out.println("������Ҫ���ҵĵ��ʣ�");
		Scanner find = new Scanner(System.in);
		
		//���ҵ���
		String fword = find.next();
		wd.search(fword);
	}

}
