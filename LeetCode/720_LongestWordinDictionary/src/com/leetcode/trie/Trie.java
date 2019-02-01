package com.leetcode.trie;

import java.util.HashMap;
import java.util.Stack;

/*
 * 字典树结构：根据题目的不同可进行相应的修改
 */

public class Trie {
	TrieNode root = new TrieNode();
	
	class TrieNode{
		boolean isWord = false;
	    HashMap<Character,TrieNode> children = new HashMap<Character, TrieNode>();
		int end = 0;
	}

	/*
	 * 根据题目修改的插入方法
	 */
	public void insert(String word, int index) {
		TrieNode node = root;
		for(char c : word.toCharArray()) {
			if(!node.children.containsKey(c)) {
				node.children.put(c, new TrieNode());
			}
			node = node.children.get(c);
		}
		node.isWord = true;
		node.end = index;
	}
	
	
	/*
	 * 深度优先搜索：使用栈结构存储节点；取到栈顶的值，处理后将其全部孩子节点入栈；
	 *          返回值为查找到的最长字符串
	 */
	public String dfs(String[] words) {
		String ans = "";
		
		//初始化节点栈
		Stack<TrieNode> stack = new Stack<TrieNode>();
		//根节点入栈
		stack.push(root);
		
		//栈不为空继续遍历
		while(!stack.empty()) {
			TrieNode node = stack.pop();
			
			if(node.end > 0 || node == root) {
				if(node != root) { //根节点不含字符，无需处理
					String word = words[node.end - 1];
					if(word.length() > ans.length() ||
							word.length() == ans.length() && word.compareTo(ans)<0) {
						ans = word;
					}
				}
				
				for(TrieNode tn : node.children.values()) {
					stack.push(tn);
				}
			}
		}
		
		return ans;
	}
}
