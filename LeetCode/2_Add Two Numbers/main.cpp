#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* p = l1;
    ListNode* q = l2;
    vector<int> num1;
    vector<int> num2;
    int temp1, temp2;

    while(p != NULL)
    {
        temp1 = p->val;
        num1.push_back(temp1);
        p = p->next;
    }

    while(q != NULL)
    {
        temp2 = q->val;
        num2.push_back(temp2);
        q = q->next;
    }

    int temp = 0;
    int count1 = num1.size();
    int count2 = num2.size();
    //int countmin, countmax;
    /*
    if(count1 <= count2)
    {
        countmin = count1;
        countmax = count2;
    }
    else
    {
        countmin = count2;
        countmax = count1;
    }
    */
    if(count1==1 && num1[0]==0)
    {
        return l2;
    }
    else if(count2==1 && num2[0]==0)
    {
        return l1;
    }
    else
    {
        //尾插法建立单链表
        ListNode* head = new ListNode(0);
        ListNode* sum, *r = head;
        int flag = 0;
        if(count1 <= count2)
        {
            for(int i=0; i<count1; i++)
            {
                temp = num1[i] + num2[i] + flag;
                if(temp >= 10)
                {
                    temp = temp % 10;
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
                sum = new ListNode(temp);
                //sum->val = temp;
                r -> next = sum;
                r = sum;
            }

            for(int j=count1; j<count2; j++)
            {
                temp = num2[j] + flag;
                if(temp >= 10)
                {
                    temp = temp % 10;
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
                sum = new ListNode(temp);
                //sum->val = temp;
                r -> next = sum;
                r = sum;
            }

            if(flag == 1)
            {
                sum = new ListNode(1);
                //sum -> val = 1;
                r -> next = sum;
                r = sum;
            }
            r -> next = NULL;
            return head -> next -> next;
        }
        else
        {
            for(int i=0; i<count2; i++)
            {
                temp = num1[i] + num2[i] + flag;
                if(temp >= 10)
                {
                    temp = temp % 10;
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
                sum = new ListNode(temp);
                //sum->val = temp;
                r -> next = sum;
                r = sum;
            }

            for(int j=count2; j<count1; j++)
            {
                temp = num1[j] + flag;
                if(temp >= 10)
                {
                    temp = temp % 10;
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
                sum = new ListNode(temp);
                //sum->val = temp;
                r -> next = sum;
                r = sum;
            }

            if(flag == 1)
            {
                sum = new ListNode(1);
                //sum -> val = 1;
                r -> next = sum;
                r = sum;
            }
            r -> next = NULL;
            return head -> next -> next;
        }
    }
}


int main()
{
    int number1, number2;
    cout << "请输入两个整数" << endl;
    cin >> number1;
    cin >> number2;

    ListNode *l1 = new ListNode(0);
    ListNode *s1, *r1 = l1;
    int remainder = 0;
    while(number1 != 0)
    {
        remainder = number1 % 10;
        s1 = new ListNode(remainder);
        //s1 -> val = remainder;
        r1 -> next = s1;
        r1 = s1;
        number1 = number1 / 10;
    }
    r1 -> next = NULL;

    ListNode *l2 = new ListNode(0);
    ListNode *s2, *r2 = l2;
    while(number2 != 0)
    {
        remainder = number2 % 10;
        s2 = new ListNode(remainder);
        //s2 -> val = remainder;
        r2 -> next = s2;
        r2 = s2;
        number2 = number2 / 10;
    }
    r2 -> next = NULL;

    ListNode *sum = addTwoNumbers(l1,l2);
    while(sum != NULL)
    {
        cout << sum -> val;
        sum = sum -> next;
    }
    return 0;
}
