/*
 * @description  ����һ����ά���ַ������һ���ַ������������ַ��������������ڽ����������ң���
 *               �ַ������ع���õ����ͷ���true�����򷵻�false��
 * @idea  ��ʵ������һ��ͼ����������������⣬���õݹ�ķ�ʽ�����
 * @author  SA18225018
 * @date   2018/10/31
 */
package solution;

import java.io.IOException;
import java.util.Scanner;

public class searchWord {

	public static void main(String[] args) {
		// ���Ժ���
		
		char[][] board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
		
		String word;
		System.out.println("������Ҫ���ҵ��ַ�����");
	    Scanner ss = new Scanner(System.in);
	    word = ss.nextLine();
				
        searchWord sw = new searchWord();
        boolean result = sw.isExistWord(board, word);
        
        System.out.println("�ַ���" + word + "�Ƿ���������еĽ��Ϊ��" + result );
        
		
        /*  ��̬�����ַ�����
        int m, n;
        Scanner sc = new Scanner(System.in);
        System.out.println("���������봴�����ַ��������������������mΪ�У�nΪ�У�");
        System.out.print("m=");
        m = sc.nextInt();
        System.out.print("n=");
        n = sc.nextInt();
        
        String range;
        char[][] board = new char[m][n];  // ����һ��m��n�е��ַ�����
        System.out.println("����������洢���ַ���");
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
        System.out.println("������Ҫ���ҵ��ַ�����");
        Scanner ss = new Scanner(System.in);
        word = ss.nextLine();
		
        searchWord sw = new searchWord();
        boolean result = sw.isExistWord(board, word);
        
        System.out.println("�ַ���" + word + "�Ƿ���������еĽ��Ϊ��" + result );
        */
	}
	
	//����������������ĵ��ã��鿴�Ƿ���ڸ��ַ�
	public boolean isExistWord(char[][] scope, String word) {
		int m = scope.length; // m�������������
		int n = scope[0].length;  // n�������������
		
		boolean result = false;  // ������ֵ����ʼΪfalse
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(DFS_search(scope, word, i, j, 0))
					return true;
			}
		}
		
		return false;
	}
	
	// ����������������������ַ�ƥ��
	public boolean DFS_search(char[][] scope, String word, int i, int j, int k) {
		// i��ʾ�ַ��������������j��ʾ�ַ��������������k��ʾ�ַ����ĵ����ַ�������
		int m = scope.length; // m�������������
		int n = scope[0].length;  // n�������������
		
		if(i<0 || j<0 || i>=m || j>=n) {
			return false;    // ����δ�ҵ�ʱ���˳����
		}
		
		//  ��������е�Ԫ�����ַ�����ǰ�ַ�ƥ��
		if(scope[i][j] == word.charAt(k)) {
			//  ��������Ԫ�ص�ֵ�ݴ棬�����ԭ����ֵ����ֹ�������ʱ�ٴα��ҵ�
			char tmp = scope[i][j];  
			scope[i][j] = '#';
			
			if(k == word.length()-1) {
				// ����Ѿ�������word�����һ���ַ����򷵻�true
				return true;
			}
			else if(DFS_search(scope,word,i-1,j,k+1)
					|| DFS_search(scope,word,i+1,j,k+1)
					|| DFS_search(scope,word,i,j-1,k+1)
					|| DFS_search(scope,word,i,j+1,k+1))
			{
				// �ݹ�������Ԫ����������λ�õ�Ԫ���Ƿ�ƥ�������ַ�������һ���ַ�������ɹ��������䣬����true
				return true;
			}
			scope[i][j] = tmp;  // Ԫ��ֵ��λ
		}
		
		return false;  // û�ҵ�����false
	}

}
