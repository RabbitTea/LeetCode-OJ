#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

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

    int count1 = num1.size();
    int count2 = num2.size();

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
        //double base1 = pow(10,count1-1);
        //double base2 = pow(10,count2-1);

        long long int base1 = 1;
        long long int base2 = 1;
        for(int i=0;i<count1-1;i++){
            base1 *= 10;
        }
        for(int i=0;i<count2-1;i++){
            base2 *= 10;
        }

        cout << base2 << endl;
        long long int n1 = 0;
        long long int n2 = 0;
        for(int i=count1-1; i>=0; i--)
        {
            n1 = n1 + num1[i] * base1;
            base1 = base1 / 10;
        }
        for(int j=count2-1; j>=0; j--)
        {
            cout << n2 << " ";
            n2 = n2 + num2[j] * base2;
            cout << n2 << endl;
            base2 = base2 / 10;
        }
        long long int sum = n1 + n2;

        cout << n1 << " " << n2 << endl;
        //cout << sum << endl;
/*
        for(int i=0;i<count2;i++){
            cout << num2[i];
        }
        cout << endl;
*/
        //cout << pow(10,2) << endl;
        //cout << base1 << " " << base2 <<endl;

        int remainder = 0;
        ListNode* head = new ListNode(0);
        ListNode* add, *r = head;
        while(sum != 0)
        {
            remainder = sum % 10;
            add = new ListNode(remainder);
            //add -> val = remainder;
            r -> next = add;
            r = add;
            sum /= 10;
        }
        r -> next = NULL;
        return head -> next;
    }

}

int main()
{
    int number1;
    long long int number2;
    cout << "请输入第一个整数" << endl;
    cin >> number1;
    cout << "请输入第二个整数" << endl;
    cin >> number2;

    cout << number1 << " " << number2 << endl;

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
        //cout << remainder << endl;
        s2 = new ListNode(remainder);
        //s2 -> val = remainder;
        r2 -> next = s2;
        r2 = s2;
        number2 = number2 / 10;
        //cout << number2 << endl;
    }
    r2 -> next = NULL;

    ListNode *sum = addTwoNumbers(l1->next,l2->next);
    while(sum != NULL)
    {
        cout << sum -> val;
        sum = sum -> next;
    }
    return 0;
}
