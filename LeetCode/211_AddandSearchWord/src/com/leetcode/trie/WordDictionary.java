package com.leetcode.trie;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

/*
 * @description�������Ŀͬ���ǹ����ֵ��������ݽṹ��ʵ����ӵ��ʺͲ��ң�
 *              �ؼ����������ڲ��ҵ���ʱ������ʵ��������ƥ�䣬��һ��.����һ����ĸ�������ƥ������һ����ĸ��
 *       ֻҪ�ڲ���ʱ������Ӧ���ж��������ɡ� 
 *       ע�����鱣�溢�ӽڵ�Ľṹ�У���cΪ'.'��һ��������c-'a'��ʾ��������Ϊ'.'��ASCII��ֵ������ֵ����ʱ�ᷢ������Խ�����
 *       ע����Ҫ���Ƕ������������λ���м�ʱ����õ�ǰ�ڵ����Ƽ���ƥ�䣻����������������ʱ����жϣ�����ѯ�����һλΪ��ʱ����жϣ�
 */

public class WordDictionary {
	private TrieNode root;
	
	class TrieNode{
		boolean isWord = false;
		HashMap<Character,TrieNode> children = new HashMap<Character,TrieNode>();
	}
	
	//���캯��
	public WordDictionary() {
		root = new TrieNode();
	}
	
	//��ӵ���
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
				
				Set<Character> keyset = node.children.keySet();  //��øýڵ�������ӽڵ㼯��
				Iterator<Character> iter = keyset.iterator();  // ���弯�ϵĵ����������Ա���
				while(iter.hasNext()) {
					char c = iter.next();
					TrieNode child = node.children.get(c);
					
					int index = i;
					if(word.charAt(i+1) == '.' && i+1 != word.length()-1) {  //�ж������ĵ�����
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
				System.out.println("��ǰ����Ϊ��"+word.charAt(i));
				node = node.children.get(word.charAt(i));
			}
			else {
				System.out.println("����"+word+"������...");
				result = false;
			    break;
			}
				
		}
		
		if(result == true){
			System.out.println("����"+word+"����...");
		}
		return result && node.isWord;
	}
	
}
