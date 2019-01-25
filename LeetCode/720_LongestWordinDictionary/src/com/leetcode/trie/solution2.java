package com.leetcode.trie;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/*
 * @idea���ɶ̵��������ַ������飬���ü��ϴ洢���ʵĵ��ʣ�
 *       ѡ�񳤶�Ϊ1��ȥ�����һ����ĸ���ڼ������Ѿ����ڵĵ��ʼ��뼯��(��ʱ��֮ǰ���е��м�����������);
 *       ��ʼ������ַ���Ϊ�գ�ÿ���жϵ�ǰ���ʳ����Ƿ���ڽ���ַ����ĳ��ȣ�����������½����
 */

public class solution2 {

	public static void main(String[] args) {
String[] words = new String[1000];
		
		System.out.println("�������ַ������飬�ö��Ÿ���");
		Scanner sc = new Scanner(System.in);
		//�������β�������������0����
		while(!sc.hasNext("0")) {
			String input = sc.next();
			
			//�����ŷָ�������Ϊ�ַ�������
			words = input.split(",");
		   
			//�õ���ַ���
			String longWord = longestWord(words);
			
			//���
			System.out.println("���ǰ׺ƥ����ַ���Ϊ��"+longWord);
			
			System.out.println("�������ַ������飬�ö��Ÿ���");
		}

	}

	public static String longestWord(String[] words) {
		String ans = "";
		
		Arrays.sort(words);   //�����ַ�������
		
		ArrayList<String> result = new ArrayList();
		
		for(String word : words) {
			if(word.length() == 1 || result.contains(word.substring(0, word.length()-1))) {
				ans = (word.length() > ans.length())? word : ans;
				result.add(word);  //�������������뼯��
			}
		}
		return ans;
	}
}
