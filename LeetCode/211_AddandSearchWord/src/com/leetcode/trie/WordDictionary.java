package com.leetcode.trie;
/*
 * @description�������Ŀͬ���ǹ����ֵ��������ݽṹ��ʵ����ӵ��ʺͲ��ң�
 *              �ؼ����������ڲ��ҵ���ʱ������ʵ��������ƥ�䣬��һ��.����һ����ĸ�������ƥ������һ����ĸ��
 *       ֻҪ�ڲ���ʱ������Ӧ���ж��������ɡ� 
 */

public class WordDictionary {
	private TrieNode root;
	
	class TrieNode{
		boolean isWord = false;
		TrieNode[] children = new TrieNode[26];
	}
	
	//���캯��
	public WordDictionary() {
		root = new TrieNode();
	}
	
	//��ӵ���
	public void addWord(String word) {
		TrieNode node = root;
		
		for(char c : word.toCharArray()) {
			if(node.children[c-'a'] == null) {
				node.children[c-'a'] = new TrieNode();  //��ĸû����ӹ������ڱ�ʾ����ĸ�������´���TrieNode�ڵ�
			}
			node = node.children[c-'a'];   //���Ƶ���ǰ�жϵ���ĸ��Ӧ�ڵ�
		}
		node.isWord = true;
		System.out.println("����"+word+"����ɹ�...");
	}

	public boolean search(String word) {
		boolean result = true;
		TrieNode node = root;
		
		for(char c : word.toCharArray()) {
			if(node.children[c-'a'] == null && c == '.') {
				node = node.children[c-'a'];
			}
			else if(node.children[c-'a'] != null) {
				node = node.children[c-'a'];
			}
			else
				System.out.println("����"+word+"������...");
			    result = false;
			    break;
		}
		
		System.out.println("����"+word+"����...");
		return result && node.isWord;
	}
	
}
