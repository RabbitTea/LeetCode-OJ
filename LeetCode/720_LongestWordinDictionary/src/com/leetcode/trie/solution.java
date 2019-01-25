package com.leetcode.trie;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

import com.leetcode.trie.Trie.TrieNode;

/*
 * @description������һ���ַ������飬�ҳ���������ܱ������������εõ����ַ���(ʵ��Ϊǰ׺ƥ��)�����õ�������򷵻��ֵ����С���Ǹ����ʣ�
 * @idea��1.����Trie����߲���Ч�ʣ������ַ�����ƥ�䣻
 *       2.�����������������в��ҡ�
 * @author��Sandra
 * @date��2019/1/25
 */

public class solution {

	public static void main(String[] args) {
		String[] words = new String[1000];
		
		System.out.println("�������ַ������飬�ö��Ÿ���");
		Scanner sc = new Scanner(System.in);
		//�������β�������������0����
		while(!sc.hasNext("0")) {
			String input = sc.next();
			
			//�����ŷָ�������Ϊ�ַ�������
			words = input.split(",");
		   
			//�õ���ַ���
			String longWord = longestWord(words);
			
			//���
			System.out.println("���ǰ׺ƥ����ַ���Ϊ��"+longWord);
			
			System.out.println("�������ַ������飬�ö��Ÿ���");
		}
	}

	public static String longestWord(String[] words) {
		
		/*
		//�����ַ�������
		Collections.sort(Arrays.asList(words));
		//Arrays.sort(words);
		*/
		
		//���ʵ乹��ΪTrie��
		Trie trie = new Trie();
		int index = 0;
		for(String word : words) {
			trie.insert(word,++index);
		}
		String longWord = trie.dfs(words);
		
		return longWord;
	}
}
