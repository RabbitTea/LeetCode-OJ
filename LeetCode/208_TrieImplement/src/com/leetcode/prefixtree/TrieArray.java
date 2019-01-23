package com.leetcode.prefixtree;

public class TrieArray {
	private TrieNode root = new TrieNode();
	
	private class TrieNode{
		//声明时初始化不用构造函数
		private boolean isWord = false;
		/*
		 * 这里使用数组结构保存孩子节点；考虑26个英文字母，元素值对应字符值，索引为该字符与字母a的ASCII码差值
		 */
		private TrieNode[] children = new TrieNode[26];  //leetcode的测试用例为26个小写英文字母
	}
	
	//插入
	public void insert(String word) {
		TrieNode node = root;
		for(char c : word.toCharArray()) { //Java中字符串和字符数组可以很方便的转换
			if(node.children[c-'a'] == null) {
				node.children[c-'a'] = new TrieNode();
			}
			node = node.children[c-'a'];
		}
		node.isWord = true;
	}
	
	//查询
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
	
	//前缀匹配
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
