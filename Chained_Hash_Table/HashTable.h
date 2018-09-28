#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <functional>
#include <stdexcept>

using namespace std;

template<class K, class V>
class HashTable
{
private:
    class List // 各个相同key值位置链接的链表
    {
    public:
        class Node // 链表中的结点
        {
        public:
            K key;
            V value;
            Node *next;
        public:
            Node(const K& k, const V& v) :key(k),value(v),next(NULL)
            {

            }
            ~Node()
            {
                if(next != NULL)
                    delete next;
            }
        };
        Node *head = NULL;
    public:
        // 单个链表中的插入键值对的操作
        int Chained_Hash_Insert(const K& k, const V& v)
        {
            if(head == NULL){
                head = new Node(k,v);
                return 1; // 返回1表示插入成功
            }
            if(head->key == k){
                head->value = v;
                return 0; //返回0表示插入失败
            }
            Node *curr = head;
            while(curr->next != NULL)
            {
                if(curr->next->key == k){
                    curr->next->value = v;
                    return 0;
                }
                curr = curr->next;
            }
            //遍历完全部链表没有发现与插入元素相同的key值
            curr->next = new Node(k,v); //在链表的最后位置插入
            return 1;
        }

        //在单个链表中按照给定的关键字查找元素值
        V Chained_Hash_Search(const K& k)
        {
            Node *curr = head;
            while(curr != NULL)
            {
                if(curr->key == k)
                    return curr->value;
                curr = curr->next;
            }
            throw std::overflow_error("cannot find");
        }

        //在单个链表中按给定关键字删除键值对
        int Chained_Hash_Delete(const K& k)
        {
            if(head == NULL)
                return 0; // 返回0表示删除失败
            if(head->key == k){
                delete head;
                head = NULL;
                return 1;
            }
            Node *curr = head;
            Node *pre = NULL;
            while(curr->next != NULL)
            {
                if(curr->next->key == k){
                    Node *temp = curr->next; // temp指针保存要删除的结点
                    curr->next = curr->next->next;
                    delete temp;
                    return 1;
                }
                pre = curr; // pre保存删除结点的前一个结点
                curr = curr->next;
            }
            //判断最后一个结点的情况
            if(curr->key == k)
            {
                delete curr;
                pre->next = NULL;
                return 1;
            }
            return 0;
        }
    }; // 表示拉链表定义的结束

    //整个散列表[包括数组和各个位置拉得链表]中共用的变量
    List *t = NULL;
    int kvcount = 0; // 键值对的个数
    int listcount = 0; // 散列表的长度[也是链表的个数]

    private:
        // 判断散列表是否为空
        bool Hash_isEmpty()
        {
            return listcount==0;
        }

        // 由散列函数得索引值[除留取余：除数为表长]
        int getHashIndex(const K& k)
        {
            return k%listcount;
        }
    public:
        // 散列表整体的构造方法
        HashTable(int m)
        {
            if(m < 1)
                cout << "invalid length of HashTable" << endl;
            t = new List[m]; // List类型的数组，表示数组中的每个元素都是一个List单链表[即每个位置都可以拉链]
            listcount = m; // m表示整个散列表的长度
        }

        // 散列表的插入
        void hash_Insert(const K& k, const V& v)
        {
            int index = getHashIndex(k); // 根据k得到要插入的键值对的索引值[即散列数组的下标]
            if(index > listcount-1)
                cout << "index over listcount" << endl;
            if(t[index].Chained_Hash_Insert(k,v)) //t[index]表示一个单链表，对其进行插入操作
                ++kvcount; // 实际插入的键值对增加
        }

        //散列表的查找
        V hash_Search(const K& k)
        {
            int index = getHashIndex(k);
            if(index > listcount-1)
                cout << "index over range" << endl;
            return t[index].Chained_Hash_Search(k);
        }

        //散列表的删除
        void hash_Delete(const K& k)
        {
            int index = getHashIndex(k);
            if(index > listcount-1)
                cout << "index over range" << endl;
            if(t[index].Chained_Hash_Delete(k))
                --kvcount; // 实际存储的键值对减少
        }

        //得到当前散列表中实际存储的键值对的个数
        int hash_Size()
        {
            return kvcount;
        }

        //散列表的析构函数
        ~HashTable()
        {
            if(t != NULL)
                delete[] t; // 依次删除t这个数组
        }
};

#endif // HASHTABLE_H_INCLUDED
