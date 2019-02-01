package com.leetcode.trie;

import java.util.HashMap;
import java.util.Stack;

/*
 * �ֵ����ṹ��������Ŀ�Ĳ�ͬ�ɽ�����Ӧ���޸�
 */

public class Trie {
	TrieNode root = new TrieNode();
	
	class TrieNode{
		boolean isWord = false;
	    HashMap<Character,TrieNode> children = new HashMap<Character, TrieNode>();
		int end = 0;
	}

	/*
	 * ������Ŀ�޸ĵĲ��뷽��
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
	 * �������������ʹ��ջ�ṹ�洢�ڵ㣻ȡ��ջ����ֵ���������ȫ�����ӽڵ���ջ��
	 *          ����ֵΪ���ҵ�����ַ���
	 */
	public String dfs(String[] words) {
		String ans = "";
		
		//��ʼ���ڵ�ջ
		Stack<TrieNode> stack = new Stack<TrieNode>();
		//���ڵ���ջ
		stack.push(root);
		
		//ջ��Ϊ�ռ�������
		while(!stack.empty()) {
			TrieNode node = stack.pop();
			
			if(node.end > 0 || node == root) {
				if(node != root) { //���ڵ㲻���ַ������账��
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
