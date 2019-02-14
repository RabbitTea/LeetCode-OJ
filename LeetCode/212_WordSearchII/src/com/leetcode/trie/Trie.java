package com.leetcode.trie;

public class Trie {
	private TrieNode root = new TrieNode();

	class TrieNode{
		char c;         //�ڵ�洢���ַ�ֵ
		boolean isWord = false;     //���ʵĽ�����־
		String dicWord = "";      //��¼�ֵ��е�һ������(����������־��Ҷ�ڵ�洢)
		TrieNode[] children = new TrieNode[26];
		
		public TrieNode() {
			
		}
		
		public TrieNode(char c) {
			this.c = c;
		}
	}
	
	public void insert(String word) {
		TrieNode node = root;
		for(char c:word.toCharArray()) {
			if(node.children[c-'a'] == null) {
				node.children[c-'a'] = new TrieNode();
			}
			node = node.children[c-'a'];
		}
		node.isWord =true;
		node.dicWord = word;
	}
	
	public boolean search(String word) {
		 TrieNode node = root;
		 boolean result = false;
		 for(char c:word.toCharArray()) {
			 if(node.children[c-'a'] == null)
				 return result;
			 node = node.children[c-'a'];
		 }
		 result = true;
		 return result && node.isWord;
	}
	
	public boolean startsWith(String prefix) {
		TrieNode node = root;
		boolean result = false;
		for(char c:prefix.toCharArray()) {
			 if(node.children[c-'a'] == null)
				 return result;
			 node = node.children[c-'a'];
		}
		result = true;
		return result;
	}
}
