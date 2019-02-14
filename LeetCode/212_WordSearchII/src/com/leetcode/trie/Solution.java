package com.leetcode.trie;

/*
 * @description��1.����Ϊ��һ����ά�ַ������У��ҳ����ڴ��������ڴʵ��еĵ��ʣ�����˼·�������������(DFS)�����õ��˵ݹ飬
 *              ѭ��������ά���飬��ÿһλ�õ�Ԫ������֮ǰ���ַ����󵽸����ʵ��н��в��ң��жϴʵ����Ƿ���ڸõ��ʣ�ͬʱע����ݣ�
 *              2.��������һ����ѯ�Ż��Ĺؼ��㣬�������ֵ����ṹ���洢�ʵ䣬���а������롢���Һ�ǰ׺ƥ��ķ�����ǰ׺ƥ�䷽�����ڼ�֦���ܣ�
 *              ��Ϊ�ݹ��˳�����֮һ��
 *              3.Ϊ������ݣ���Ҫ������ά���飬��Ϊ�������ͣ��洢��ӦԪ���Ƿ񱻷��ʹ���
 */

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Solution {
	
	//ʹ��set���ϴ洢��������������ظ�Ԫ�ص����ԣ�����board���ظ�����ĸ�����ظ��ĵ���
	static Set<String> res = new HashSet<String>();
	
	/*
	 * ѭ������board�������京�е��ֵ��еĵ���
	 */
	public static List<String> findWords(char[][] board, String[] words){
		//ʹ��ǰ׺���ṹ���Ż���ѯЧ��
		Trie trie = new Trie();
		
		//���ʵ�words����Ϊǰ׺��
		for(String w:words) {
			trie.insert(w);
		}
		
		/*
		 * ׼��ѭ������
		 */
		int m = board.length;  //m��ʾ����
		int n = board[0].length;    //n��ʾ����
		boolean[][] isVisited = new boolean[m][n];    //�������͵Ķ�ά���飬�洢��Ӧ��Ԫ�Ƿ񱻷��ʹ��������ظ�����
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				recFindWords(board,isVisited,"",i,j,trie);
			}
		}
		
		return new ArrayList<String>(res);   //��set����ת��ΪArrayList����
	}
	
	
	/*
	 * �ݹ���board�в��ҵ���
	 * @param��
	 *        char[][] board����֪��ά�ַ�����
	 *        boolean[][] isVisited���������Ķ�ά�������飬�洢��ӦԪ���Ƿ񱻷��ʹ�
	 *        String str���Ѿ���ɵ��ַ���(�������Ϊ�����ʵ��е�ǰ׺)
	 *        int x, int y���ֱ��ʾ��ǰ����������������
	 *        Trie trie�����ݸ����ʵ佨����ǰ׺���ṹ
	 */
	public static void recFindWords(char[][] board, boolean[][] isVisited, String str, int x, int y, Trie trie) {
		//�ݹ��˳�����(3��)
		if(x<0 || x>=board.length || y<0 || y>=board[0].length)   //ע������Ҫд�ϡ�=���ţ������������Խ��Ĵ���
			return;
		if(isVisited[x][y])
			return;
		
		String curstr = str + board[x][y];   //Ĭ���ַ���������ϵ�ǰλ�õ��ַ�
		//�жϵ�ǰ�ַ������ֵ������Ƿ�Ϊǰ׺�������������ֵ����ļ�֦���ܣ�����䲻��ǰ׺���䲻���ֵ����еĵ��ʣ�ֱ�ӷ��ؼ���
		if(!trie.startsWith(curstr))
			return;
		
		if(trie.search(curstr)) {
			res.add(curstr);
		}
			
		isVisited[x][y] = true;    //���ö�Ӧ���ʱ�־Ϊtrue
		
		//�ڸ�λ���������´��ֱ�ݹ����
		recFindWords(board, isVisited, curstr, x-1, y, trie);
		recFindWords(board, isVisited, curstr, x+1, y, trie);
		recFindWords(board, isVisited, curstr, x, y-1, trie);
		recFindWords(board, isVisited, curstr, x, y+1, trie);
		

		//��ע�����
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
		System.out.println("������ʵ��еĵ��ʣ�");
		String inputCon = "";
		
		inputCon = sc.nextLine();   //nextline�᷵�ػس�ǰ�������ַ���next��Ե��ո�
		String[] words = inputCon.split(" ");
		
		//Scanner input = new Scanner(System.in);
		//System.out.println("���������");
		*/
		
		System.out.println("���ҽ��Ϊ��");
		List<String> res = new ArrayList<>();
		res = findWords(board, words);
		for(int i=0;i<res.size();i++) {
			System.out.print("\""+res.get(i)+"\""+" ");
		}
	}

}
