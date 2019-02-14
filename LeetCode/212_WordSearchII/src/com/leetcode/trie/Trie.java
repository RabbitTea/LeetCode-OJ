package com.leetcode.trie;

public class Trie {
	private TrieNode root = new TrieNode();

	class TrieNode{
		char c;         //节点存储的字符值
		boolean isWord = false;     //单词的结束标志
		String dicWord = "";      //记录字典中的一个单词(仅含结束标志的叶节点存储)
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
