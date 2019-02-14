package com.leetcode.trie;

/*
 * @description：1.题意为在一个二维字符数组中，找出相邻串联的且在词典中的单词；基本思路是深度优先搜索(DFS)——用到了递归，
 *              循环遍历二维数组，对每一位置的元素连接之前的字符串后到给定词典中进行查找，判断词典中是否存在该单词；同时注意回溯；
 *              2.△这里有一个查询优化的关键点，即利用字典树结构来存储词典，其中包含插入、查找和前缀匹配的方法；前缀匹配方法用于剪枝功能，
 *              作为递归退出条件之一；
 *              3.为方便回溯，需要辅助二维数组，其为布尔类型，存储对应元素是否被访问过。
 */

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Solution {
	
	//使用set集合存储结果，利用其无重复元素的特性，避免board中重复的字母导致重复的单词
	static Set<String> res = new HashSet<String>();
	
	/*
	 * 循环遍历board，查找其含有的字典中的单词
	 */
	public static List<String> findWords(char[][] board, String[] words){
		//使用前缀树结构，优化查询效率
		Trie trie = new Trie();
		
		//将词典words建立为前缀树
		for(String w:words) {
			trie.insert(w);
		}
		
		/*
		 * 准备循环条件
		 */
		int m = board.length;  //m表示行数
		int n = board[0].length;    //n表示列数
		boolean[][] isVisited = new boolean[m][n];    //布尔类型的二维数组，存储对应单元是否被访问过，避免重复访问
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				recFindWords(board,isVisited,"",i,j,trie);
			}
		}
		
		return new ArrayList<String>(res);   //将set类型转换为ArrayList类型
	}
	
	
	/*
	 * 递归在board中查找单词
	 * @param：
	 *        char[][] board：已知二维字符数组
	 *        boolean[][] isVisited：已声明的二维布尔数组，存储对应元素是否被访问过
	 *        String str：已经组成的字符串(可以理解为给定词典中的前缀)
	 *        int x, int y：分别表示当前的行索引和列索引
	 *        Trie trie：根据给定词典建立的前缀树结构
	 */
	public static void recFindWords(char[][] board, boolean[][] isVisited, String str, int x, int y, Trie trie) {
		//递归退出条件(3个)
		if(x<0 || x>=board.length || y<0 || y>=board[0].length)   //注意这里要写上“=”号，否则会有数组越界的错误
			return;
		if(isVisited[x][y])
			return;
		
		String curstr = str + board[x][y];   //默认字符串先添加上当前位置的字符
		//判断当前字符串在字典树中是否为前缀，这里利用了字典树的剪枝功能，如果其不是前缀则其不是字典树中的单词，直接返回即可
		if(!trie.startsWith(curstr))
			return;
		
		if(trie.search(curstr)) {
			res.add(curstr);
		}
			
		isVisited[x][y] = true;    //设置对应访问标志为true
		
		//在该位置左右上下处分别递归查找
		recFindWords(board, isVisited, curstr, x-1, y, trie);
		recFindWords(board, isVisited, curstr, x+1, y, trie);
		recFindWords(board, isVisited, curstr, x, y-1, trie);
		recFindWords(board, isVisited, curstr, x, y+1, trie);
		

		//△注意回溯
		isVisited[x][y] = false;
		
	}

	public static void main(String[] args) {
		//ArrayList<String> dictionary = new ArrayList<>();
		//ArrayList<Character[]> aryboard = new ArrayList<>();
		char[][] board = { {'o','a','a','n'},
				{'e','t','a','e'},
				{'i','h','k','r'},
				{'i','f','l','v'}}; 
		String[] words = {"oath","pea","eat","rain"};
		
		/*
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入词典中的单词：");
		String inputCon = "";
		
		inputCon = sc.nextLine();   //nextline会返回回车前的所有字符，next会吃掉空格
		String[] words = inputCon.split(" ");
		
		//Scanner input = new Scanner(System.in);
		//System.out.println("请输入矩阵");
		*/
		
		System.out.println("查找结果为：");
		List<String> res = new ArrayList<>();
		res = findWords(board, words);
		for(int i=0;i<res.size();i++) {
			System.out.print("\""+res.get(i)+"\""+" ");
		}
	}

}
