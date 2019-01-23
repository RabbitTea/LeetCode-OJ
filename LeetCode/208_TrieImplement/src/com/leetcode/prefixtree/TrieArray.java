package com.leetcode.prefixtree;

public class TrieArray {
	private TrieNode root = new TrieNode();
	
	private class TrieNode{
		//����ʱ��ʼ�����ù��캯��
		private boolean isWord = false;
		/*
		 * ����ʹ������ṹ���溢�ӽڵ㣻����26��Ӣ����ĸ��Ԫ��ֵ��Ӧ�ַ�ֵ������Ϊ���ַ�����ĸa��ASCII���ֵ
		 */
		private TrieNode[] children = new TrieNode[26];  //leetcode�Ĳ�������Ϊ26��СдӢ����ĸ
	}
	
	//����
	public void insert(String word) {
		TrieNode node = root;
		for(char c : word.toCharArray()) { //Java���ַ������ַ�������Ժܷ����ת��
			if(node.children[c-'a'] == null) {
				node.children[c-'a'] = new TrieNode();
			}
			node = node.children[c-'a'];
		}
		node.isWord = true;
	}
	
	//��ѯ
	public boolean search(String word) {
		TrieNode node = root;
		for(char c : word.toCharArray()) {
			if(node.children[c-'a'] == null) {
				return false;
			}
			node = node.children[c-'a'];
		}
		return node.isWord;
	}
	
	//ǰ׺ƥ��
	public boolean startsWith(String prefix) {
		TrieNode node = root;
		for(char c : prefix.toCharArray()) {
			if(node.children[c-'a'] == null) {
				return false;
			}
			node = node.children[c-'a'];
		}
		return true;
	}
}
