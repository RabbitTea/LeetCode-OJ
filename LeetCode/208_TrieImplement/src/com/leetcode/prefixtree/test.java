package com.leetcode.prefixtree;

import java.util.Scanner;

public class test {

	public static void main(String[] args) {
		//�����ֵ���
		Trie trie = new Trie();
		
		//���뵥��
		System.out.println("������Ҫ����ĵ��ʣ�");
		Scanner sc = new Scanner(System.in);
		String wordIn = sc.nextLine();
		trie.insert(wordIn);
		
		//��ѯ����
		System.out.println("������Ҫ��ѯ�ĵ��ʣ�");
		Scanner query = new Scanner(System.in);
		String wordFind = query.nextLine();
		trie.search(wordFind);
		
		//ǰ׺ƥ��
		System.out.println("������Ҫƥ���ǰ׺��");
		Scanner in = new Scanner(System.in);
		String prefix = in.nextLine();
		trie.startsWith(prefix);
	}

}
