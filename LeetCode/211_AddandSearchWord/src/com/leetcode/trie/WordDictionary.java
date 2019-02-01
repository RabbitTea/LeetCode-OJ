package com.leetcode.trie;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

/*
 * @description：这道题目同样是构造字典树的数据结构，实现添加单词和查找；
 *              关键的区别在于查找单词时，可以实现类正则化匹配，即一个.代表一个字母，其可以匹配任意一个字母；
 *       只要在查找时加上相应的判断条件即可。 
 *       注：数组保存孩子节点的结构中，若c为'.'，一定不能用c-'a'表示索引，因为'.'的ASCII码值不是正值，此时会发生数组越界错误；
 *       注：需要考虑多种情况——点位于中间时如何让当前节点下移继续匹配；当两个或多个点相连时如何判断；当查询串最后一位为点时如何判断；
 */

public class WordDictionary {
	private TrieNode root;
	
	class TrieNode{
		boolean isWord = false;
		HashMap<Character,TrieNode> children = new HashMap<Character,TrieNode>();
	}
	
	//构造函数
	public WordDictionary() {
		root = new TrieNode();
	}
	
	//添加单词
	public void addWord(String word) {
		TrieNode node = root;
		
		for(char c : word.toCharArray()) {
			if(!node.children.containsKey(c)) {
				node.children.put(c, new TrieNode());
			}
			node = node.children.get(c);
		}
		
		node.isWord = true;
	}

	public boolean search(String word) {
		
		TrieNode node = root;
		boolean result = true;
		System.out.println("in search method...");
		
		for(int i=0;i<word.length();i++) {
			
			System.out.println("in travel word...");
			
			if(word.charAt(i) == '.' && i != word.length()-1) {
				
				Set<Character> keyset = node.children.keySet();  //获得该节点的所有子节点集合
				Iterator<Character> iter = keyset.iterator();  // 定义集合的迭代器，用以遍历
				while(iter.hasNext()) {
					char c = iter.next();
					TrieNode child = node.children.get(c);
					
					int index = i;
					if(word.charAt(i+1) == '.' && i+1 != word.length()-1) {  //判断相连的点的情况
						i++;
						Set<Character> ks = child.children.keySet();
						Iterator<Character> it = ks.iterator();
						while(it.hasNext()) {
							char nextc = it.next();
							if(child.children.get(nextc).children.containsKey(word.charAt(i+1))) {
								node = child.children.get(word.charAt(i+1));
							}
							break;
						}
					}
						
					if(child.children.containsKey(word.charAt(i+1))) {
						node = node.children.get(c);
						break;
					}
				}
			}
			else if(i == word.length()-1 && word.charAt(i) == '.') {
				result = true;
			}
			else if(node.children != null && node.children.containsKey(word.charAt(i))) {
				System.out.println("当前单词为："+word.charAt(i));
				node = node.children.get(word.charAt(i));
			}
			else {
				System.out.println("单词"+word+"不存在...");
				result = false;
			    break;
			}
				
		}
		
		if(result == true){
			System.out.println("单词"+word+"存在...");
		}
		return result && node.isWord;
	}
	
}
