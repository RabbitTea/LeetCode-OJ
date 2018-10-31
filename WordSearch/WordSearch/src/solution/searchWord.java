/*
 * @description  给定一个二维的字符数组和一个字符串，如果这个字符串能由数组中邻近（上下左右）的
 *               字符连续地构造得到，就返回true，否则返回false；
 * @idea  这实质上是一个图的深度优先搜索问题，运用递归的方式来解决
 * @author  SA18225018
 * @date   2018/10/31
 */
package solution;

import java.io.IOException;
import java.util.Scanner;

public class searchWord {

	public static void main(String[] args) {
		// 测试函数
		
		char[][] board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
		
		String word;
		System.out.println("请输入要查找的字符串：");
	    Scanner ss = new Scanner(System.in);
	    word = ss.nextLine();
				
        searchWord sw = new searchWord();
        boolean result = sw.isExistWord(board, word);
        
        System.out.println("字符串" + word + "是否存在数组中的结果为：" + result );
        
		
        /*  动态输入字符数组
        int m, n;
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入您想创建的字符数组的行数与列数——m为行，n为列：");
        System.out.print("m=");
        m = sc.nextInt();
        System.out.print("n=");
        n = sc.nextInt();
        
        String range;
        char[][] board = new char[m][n];  // 创建一个m行n列的字符数组
        System.out.println("请依次输入存储的字符：");
        range = sc.nextline();
        int k = 0; 
        for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
			    char[i][j] = word.charAt(k);
			    k++;
			}
		}
        
        String word;
        System.out.println("请输入要查找的字符串：");
        Scanner ss = new Scanner(System.in);
        word = ss.nextLine();
		
        searchWord sw = new searchWord();
        boolean result = sw.isExistWord(board, word);
        
        System.out.println("字符串" + word + "是否存在数组中的结果为：" + result );
        */
	}
	
	//深度优先搜索函数的调用，查看是否存在该字符
	public boolean isExistWord(char[][] scope, String word) {
		int m = scope.length; // m保存数组的行数
		int n = scope[0].length;  // n保存数组的列数
		
		boolean result = false;  // 保存结果值，初始为false
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(DFS_search(scope, word, i, j, 0))
					return true;
			}
		}
		
		return false;
	}
	
	// 深度优先搜索函数，进行字符匹配
	public boolean DFS_search(char[][] scope, String word, int i, int j, int k) {
		// i表示字符数组的行索引，j表示字符数组的列索引，k表示字符串的单个字符的索引
		int m = scope.length; // m保存数组的行数
		int n = scope[0].length;  // n保存数组的列数
		
		if(i<0 || j<0 || i>=m || j>=n) {
			return false;    // 定义未找到时的退出情况
		}
		
		//  如果数组中的元素与字符串当前字符匹配
		if(scope[i][j] == word.charAt(k)) {
			//  将该数组元素的值暂存，并清掉原来的值，防止深度搜索时再次被找到
			char tmp = scope[i][j];  
			scope[i][j] = '#';
			
			if(k == word.length()-1) {
				// 如果已经搜索到word的最后一个字符，则返回true
				return true;
			}
			else if(DFS_search(scope,word,i-1,j,k+1)
					|| DFS_search(scope,word,i+1,j,k+1)
					|| DFS_search(scope,word,i,j-1,k+1)
					|| DFS_search(scope,word,i,j+1,k+1))
			{
				// 递归搜索该元素上下左右位置的元素是否匹配输入字符串的下一个字符，如果成功进入该语句，返回true
				return true;
			}
			scope[i][j] = tmp;  // 元素值归位
		}
		
		return false;  // 没找到返回false
	}

}
