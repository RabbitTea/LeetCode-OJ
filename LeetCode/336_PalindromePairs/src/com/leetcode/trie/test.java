package com.leetcode.trie;

import java.util.List;
import java.util.Scanner;

public class test {

	public static void main(String[] args) {
	     	
		System.out.println("请输入单词数组：");
        Scanner sc = new Scanner(System.in);
        
        String content = sc.nextLine();
        String[] words = content.split(" ");
        
        Solution sl = new Solution();
        List<List<Integer>> res = sl.palindromePairs(words);
        System.out.println("回文串为：");
        for(List<Integer> list:res) {
        	System.out.println(list);
        }
	}

}
