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
    class List // ������ͬkeyֵλ�����ӵ�����
    {
    public:
        class Node // �����еĽ��
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
        // ���������еĲ����ֵ�ԵĲ���
        int Chained_Hash_Insert(const K& k, const V& v)
        {
            if(head == NULL){
                head = new Node(k,v);
                return 1; // ����1��ʾ����ɹ�
            }
            if(head->key == k){
                head->value = v;
                return 0; //����0��ʾ����ʧ��
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
            //������ȫ������û�з��������Ԫ����ͬ��keyֵ
            curr->next = new Node(k,v); //����������λ�ò���
            return 1;
        }

        //�ڵ��������а��ո����Ĺؼ��ֲ���Ԫ��ֵ
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

        //�ڵ��������а������ؼ���ɾ����ֵ��
        int Chained_Hash_Delete(const K& k)
        {
            if(head == NULL)
                return 0; // ����0��ʾɾ��ʧ��
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
                    Node *temp = curr->next; // tempָ�뱣��Ҫɾ���Ľ��
                    curr->next = curr->next->next;
                    delete temp;
                    return 1;
                }
                pre = curr; // pre����ɾ������ǰһ�����
                curr = curr->next;
            }
            //�ж����һ���������
            if(curr->key == k)
            {
                delete curr;
                pre->next = NULL;
                return 1;
            }
            return 0;
        }
    }; // ��ʾ��������Ľ���

    //����ɢ�б�[��������͸���λ����������]�й��õı���
    List *t = NULL;
    int kvcount = 0; // ��ֵ�Եĸ���
    int listcount = 0; // ɢ�б�ĳ���[Ҳ������ĸ���]

    private:
        // �ж�ɢ�б��Ƿ�Ϊ��
        bool Hash_isEmpty()
        {
            return listcount==0;
        }

        // ��ɢ�к���������ֵ[����ȡ�ࣺ����Ϊ��]
        int getHashIndex(const K& k)
        {
            return k%listcount;
        }
    public:
        // ɢ�б�����Ĺ��췽��
        HashTable(int m)
        {
            if(m < 1)
                cout << "invalid length of HashTable" << endl;
            t = new List[m]; // List���͵����飬��ʾ�����е�ÿ��Ԫ�ض���һ��List������[��ÿ��λ�ö���������]
            listcount = m; // m��ʾ����ɢ�б�ĳ���
        }

        // ɢ�б�Ĳ���
        void hash_Insert(const K& k, const V& v)
        {
            int index = getHashIndex(k); // ����k�õ�Ҫ����ļ�ֵ�Ե�����ֵ[��ɢ��������±�]
            if(index > listcount-1)
                cout << "index over listcount" << endl;
            if(t[index].Chained_Hash_Insert(k,v)) //t[index]��ʾһ��������������в������
                ++kvcount; // ʵ�ʲ���ļ�ֵ������
        }

        //ɢ�б�Ĳ���
        V hash_Search(const K& k)
        {
            int index = getHashIndex(k);
            if(index > listcount-1)
                cout << "index over range" << endl;
            return t[index].Chained_Hash_Search(k);
        }

        //ɢ�б��ɾ��
        void hash_Delete(const K& k)
        {
            int index = getHashIndex(k);
            if(index > listcount-1)
                cout << "index over range" << endl;
            if(t[index].Chained_Hash_Delete(k))
                --kvcount; // ʵ�ʴ洢�ļ�ֵ�Լ���
        }

        //�õ���ǰɢ�б���ʵ�ʴ洢�ļ�ֵ�Եĸ���
        int hash_Size()
        {
            return kvcount;
        }

        //ɢ�б����������
        ~HashTable()
        {
            if(t != NULL)
                delete[] t; // ����ɾ��t�������
        }
};

#endif // HASHTABLE_H_INCLUDED
