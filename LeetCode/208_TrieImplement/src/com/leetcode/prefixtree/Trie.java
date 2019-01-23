package com.leetcode.prefixtree;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/*
 * @description:前缀树/字典树原理————
 *              基本结构：树形逻辑结构，一种哈希树的变种，又称单词查找树或键树；
 *              特点：1.根节点不包含字符，除根节点外每一个节点都只包含一个字符；
 *                  2.每个节点的所有子节点包含的字符都不相同，即有m种字符，则内部节点的分支数最多为m，空间换时间的体现；
 *                  3.从根节点到某一个[被标记的]节点（不一定是叶节点），路径上经过的字符可连接为一个字符串，为该标记节点对应的字符串；
 *                  4.插入查找的时间复杂度为O(n)，其中n为字符串长度。
 *              典型应用：1.用于统计和排序大量的字符串(但不仅限于字符串)，如搜索引擎系统用于文本词频统计；
 *                    2.用于前缀匹配；
 *              优点：最大限度地减少字符串的比较，查询效率比哈希表高。
 *              缺点：空间开销大。
 * @method:这里孩子节点的结构采用Map类型，减少查找时间；
 * @author:Sandra
 * @date:2019/1/23
 */

//字典树类
public class Trie {
	private TrieNode root;  //字典树根节点 
	
	//字典树节点类
	private class TrieNode{
		/*
		 * 注意这里的孩子是深度向下的子孙节点，而非同一层上的同等级孩子
		 */
		private Map<Character, TrieNode> children;  //孩子节点定义为Map类型，其中key为字符值，value为字典树节点
		private boolean isWord;

		//构造函数
		public TrieNode() {
			children = new HashMap<Character,TrieNode>();  //HashMap具体实现
			isWord = false;
		}
	}
	
	//字典树构造函数
	public Trie() {
		root = new TrieNode();  //分配内存
		root.isWord = false;
	}
	
	//字典树的插入：根据输入的字符串进行插入
	public void insert(String word) {
		TrieNode node = root;  //node保存当前父节点
		for(int i=0;i<word.length();i++) {
			Character c = new Character(word.charAt(i)); //取字符，注意这里转换为Character类型
			if(!node.children.containsKey(c)) { //字符值未在树中出现
				node.children.put(c, new TrieNode());
			}
			node = node.children.get(c);  //下移节点			
		}
		node.isWord = true;  //单词结束，进行标记
	}
	
	//字典树的查询：根据输入的字符串进行查询
	public boolean search(String word) {
		boolean result = true;
		TrieNode node = root;
		
		for(int i=0;i<word.length();i++) {
			Character c = new Character(word.charAt(i));
			if(!node.children.containsKey(c)) {
				result = false;
				System.out.println("sorry，不存在该单词...");
				break;
			}
			node = node.children.get(c);  //当前节点下移，继续匹配
		}
		
		if(result && node.isWord) {
			System.out.println("存在单词"+word+"...");
		}
		return result && node.isWord;  //△注意完全匹配的最后一个字符一定要带有结束标记才是存在的单词
	}
	
	//字典树的前缀匹配：根据输入的前缀字符串进行匹配
	public boolean startsWith(String prefix) {
		boolean result = true;
		TrieNode node = root;
		for(int i=0;i<prefix.length();i++) {
			Character c = new Character(prefix.charAt(i));
			if(!node.children.containsKey(c)) {
				result = false;
				System.out.println("不存在含该前缀的单词...");
				break;
			}
			node = node.children.get(c);
		}
		
		if(result == true) {
			System.out.println("存在含前缀"+prefix+"的单词...");
		}
		return result;
	}
}