### 1. Two Sum(basic)

* basic为n^2复杂度，时间148ms；

---



### 1.Two Sum(Hash Table)

* Hash_Table用了哈希表，时间4ms；

---



### 2. Add Two Numbers

* 将链表中的数按低位到高位读到动态数组中，直接进行每一位的相加，保存到新链表的结点中，运行时间32ms，估计是读数组占用了一定的时间；

---



### 2. Add Two Numbers(CalSumFirst)

* 计算由链表倒序表示的两个整型数之和，该思路是先提取出两个数字并求和，再倒序存存储到链表中；

---



### 3. LongestSubstring

* 给定一个字符串，返回最大无重复子串的长度(注意是子串而不是子序列，子串要求连续)；

---



### 21. [MergeSortedLinkedList(Java)](https://github.com/RabbitTea/LeetCode-OJ/tree/master/MergeSortedLinkedList)

* 合并两个有序的链表；
* Java实现；

---



### 21. [MergeTwoLists(C++)](https://github.com/RabbitTea/LeetCode-OJ/tree/master/MergeTwoLists)

* 合并两个有序的链表；
* C++实现；

---



### 73. [MatrixSetZero](https://github.com/RabbitTea/LeetCode-OJ/tree/master/MatrixSetZero/MatrixSetZero)

* 矩阵置0：空间复杂度控制在恒定的O(1)，利用第一行和第一列的元素存储是否需要将当前行/列置0，设置两个标志位判断第一行和列是否要为0；

---



### 77. [All_CombinationofK](https://github.com/RabbitTea/LeetCode-OJ/tree/master/All_CombinationofK)

* 给定整数范围的区间为[1,n]，且给出子数组元素的个数k，输出[1,n]之间所有含k个元素的子数组——暴力方法；

---



### 79. [WordSearch](https://github.com/RabbitTea/LeetCode-OJ/tree/master/WordSearch/WordSearch)

* 给定一个二维的字符数组和一个字符串，如果这个字符串能由数组中邻近（上下左右）的字符连续地构造得到，就返回true，否则返回false；

---



### 104. [MaximumDepthOfBinaryTree](https://github.com/RabbitTea/LeetCode-OJ/tree/master/MaximumDepthOfBinaryTree)

* 递归算法找到二叉树的最大深度；

---



### 142.[LinkedListCycle](https://github.com/RabbitTea/LeetCode-OJ/tree/master/LinkedListCycle)

* 判断一个链表是否存在环，若存在则返回该环开始的节点；空间复杂度为O(1)；

---



### 203.[RemoveEofLinkedList](https://github.com/RabbitTea/LeetCode-OJ/tree/master/RemoveEofLinkedList/RemoveEofLinkedList)

* 输入一个整型单链表和一个int值，删除单链表中所有数据域与该值相同的节点，并返回修改后的单链表；

---



### 328.[OddEvenLinkedList](https://github.com/RabbitTea/LeetCode-OJ/tree/master/OddEvenLinkedList)

* 改变单链表结构，先链接索引为奇数的节点，再链接索引为偶数的节点；时间复杂度为O(n)，空间复杂度为O(1)；

---



### 617.[MergeTwoBinaryTrees](https://github.com/RabbitTea/LeetCode-OJ/tree/master/MergeTwoBinaryTrees)

* 合并两棵二叉树；

---



### 654.[MaximumBinaryTree](https://github.com/RabbitTea/LeetCode-OJ/tree/master/MaximumBinaryTree)

* 递归算法建立最大二叉树；

---



### 700.[SearchBinarySearchTree](https://github.com/RabbitTea/LeetCode-OJ/tree/master/SearchBinarySearchTree)

* 

---



### 771.[Total_Same_Char](https://github.com/RabbitTea/LeetCode-OJ/tree/master/Total_Same_Char)

* 给定两个字符串J和S，返回S中字符较J中字符相同的个数（大小写敏感）；

---



### 876.[FindMiddleNode(C++)](https://github.com/RabbitTea/LeetCode-OJ/tree/master/FindMiddleNode)

* 

---



### 876.[SearchMiddleNode(Java)](https://github.com/RabbitTea/LeetCode-OJ/tree/master/SearchMiddleNode)

* 