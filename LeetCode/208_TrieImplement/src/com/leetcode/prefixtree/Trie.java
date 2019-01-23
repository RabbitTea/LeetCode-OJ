package com.leetcode.prefixtree;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/*
 * @description:ǰ׺��/�ֵ���ԭ��������
 *              �����ṹ�������߼��ṹ��һ�ֹ�ϣ���ı��֣��ֳƵ��ʲ������������
 *              �ص㣺1.���ڵ㲻�����ַ��������ڵ���ÿһ���ڵ㶼ֻ����һ���ַ���
 *                  2.ÿ���ڵ�������ӽڵ�������ַ�������ͬ������m���ַ������ڲ��ڵ�ķ�֧�����Ϊm���ռ任ʱ������֣�
 *                  3.�Ӹ��ڵ㵽ĳһ��[����ǵ�]�ڵ㣨��һ����Ҷ�ڵ㣩��·���Ͼ������ַ�������Ϊһ���ַ�����Ϊ�ñ�ǽڵ��Ӧ���ַ�����
 *                  4.������ҵ�ʱ�临�Ӷ�ΪO(n)������nΪ�ַ������ȡ�
 *              ����Ӧ�ã�1.����ͳ�ƺ�����������ַ���(�����������ַ���)������������ϵͳ�����ı���Ƶͳ�ƣ�
 *                    2.����ǰ׺ƥ�䣻
 *              �ŵ㣺����޶ȵؼ����ַ����ıȽϣ���ѯЧ�ʱȹ�ϣ��ߡ�
 *              ȱ�㣺�ռ俪����
 * @method:���ﺢ�ӽڵ�Ľṹ����Map���ͣ����ٲ���ʱ�䣻
 * @author:Sandra
 * @date:2019/1/23
 */

//�ֵ�����
public class Trie {
	private TrieNode root;  //�ֵ������ڵ� 
	
	//�ֵ����ڵ���
	private class TrieNode{
		/*
		 * ע������ĺ�����������µ�����ڵ㣬����ͬһ���ϵ�ͬ�ȼ�����
		 */
		private Map<Character, TrieNode> children;  //���ӽڵ㶨��ΪMap���ͣ�����keyΪ�ַ�ֵ��valueΪ�ֵ����ڵ�
		private boolean isWord;

		//���캯��
		public TrieNode() {
			children = new HashMap<Character,TrieNode>();  //HashMap����ʵ��
			isWord = false;
		}
	}
	
	//�ֵ������캯��
	public Trie() {
		root = new TrieNode();  //�����ڴ�
		root.isWord = false;
	}
	
	//�ֵ����Ĳ��룺����������ַ������в���
	public void insert(String word) {
		TrieNode node = root;  //node���浱ǰ���ڵ�
		for(int i=0;i<word.length();i++) {
			Character c = new Character(word.charAt(i)); //ȡ�ַ���ע������ת��ΪCharacter����
			if(!node.children.containsKey(c)) { //�ַ�ֵδ�����г���
				node.children.put(c, new TrieNode());
			}
			node = node.children.get(c);  //���ƽڵ�			
		}
		node.isWord = true;  //���ʽ��������б��
	}
	
	//�ֵ����Ĳ�ѯ������������ַ������в�ѯ
	public boolean search(String word) {
		boolean result = true;
		TrieNode node = root;
		
		for(int i=0;i<word.length();i++) {
			Character c = new Character(word.charAt(i));
			if(!node.children.containsKey(c)) {
				result = false;
				System.out.println("sorry�������ڸõ���...");
				break;
			}
			node = node.children.get(c);  //��ǰ�ڵ����ƣ�����ƥ��
		}
		
		if(result && node.isWord) {
			System.out.println("���ڵ���"+word+"...");
		}
		return result && node.isWord;  //��ע����ȫƥ������һ���ַ�һ��Ҫ���н�����ǲ��Ǵ��ڵĵ���
	}
	
	//�ֵ�����ǰ׺ƥ�䣺���������ǰ׺�ַ�������ƥ��
	public boolean startsWith(String prefix) {
		boolean result = true;
		TrieNode node = root;
		for(int i=0;i<prefix.length();i++) {
			Character c = new Character(prefix.charAt(i));
			if(!node.children.containsKey(c)) {
				result = false;
				System.out.println("�����ں���ǰ׺�ĵ���...");
				break;
			}
			node = node.children.get(c);
		}
		
		if(result == true) {
			System.out.println("���ں�ǰ׺"+prefix+"�ĵ���...");
		}
		return result;
	}
}