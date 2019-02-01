package com.leetcode.trie;
/*
 * @description：这道题目同样是构造字典树的数据结构，实现添加单词和查找；
 *              关键的区别在于查找单词时，可以实现类正则化匹配，即一个.代表一个字母，其可以匹配任意一个字母；
 *       只要在查找时加上相应的判断条件即可。 
 */

public class WordDictionary {
	private TrieNode root;
	
	class TrieNode{
		boolean isWord = false;
		TrieNode[] children = new TrieNode[26];
	}
	
	//构造函数
	public WordDictionary() {
		root = new TrieNode();
	}
	
	//添加单词
	public void addWord(String word) {
		TrieNode node = root;
		
		for(char c : word.toCharArray()) {
			if(node.children[c-'a'] == null) {
				node.children[c-'a'] = new TrieNode();  //字母没有添加过，即在表示该字母的索引下存入TrieNode节点
			}
			node = node.children[c-'a'];   //下移到当前判断的字母对应节点
		}
		node.isWord = true;
		System.out.println("单词"+word+"插入成功...");
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
				System.out.println("单词"+word+"不存在...");
			    result = false;
			    break;
		}
		
		System.out.println("单词"+word+"存在...");
		return result && node.isWord;
	}
	
}
