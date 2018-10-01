/**
 * @Description:QuickSort
 * @author Liyue Cao
 * @number SA18225018
 */
package com.myQuickSort;

public abstract class QuickSort {
	//分离
	private static int Partition(int[] A,int p,int r) {
		int pivot = A[r];
		int i = p-1;
		for(int j=p;j<r;j++){
			if(A[j] <= pivot) {
				i = i + 1;
				int temp = A[j];
				A[j] = A[i];
				A[i] = temp;
			}
		}
		i = i + 1;
		int temp = A[r];
		A[r] = A[i];
		A[i] = temp;
		return i;
	}
	
	//排序
	private static void QuickSort(int[] A,int p,int r) {
		int q;
		if(p < r) {
			q = Partition(A,p,r);
			QuickSort(A,p,q-1);
			QuickSort(A,q+1,r);
		}
	}

	public static void main(String[] args) {
		int[] A = {3,5,2,7,6,8,1,9,4,0};
		
		System.out.println("数组原始的顺序为：");
		for(int i=0;i<10;i++) {
			System.out.print(A[i]+" ");
		}
		System.out.println();
		
		QuickSort(A,0,9);
		System.out.println("排序后的顺序为：");
		//输出
		for(int i=0;i<10;i++) {
			System.out.print(A[i]+" ");
		}
	}

}
