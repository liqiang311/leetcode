/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void PushBack(ListNode *Node, int x)
{
	ListNode *l = Node;
	while(l->next != NULL)
		l = l->next;
	ListNode *newNode = new ListNode(x);
	l->next = newNode;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		int carry;
		carry = (l1->val + l2->val) / 10;
        ListNode* ret = new ListNode((l1->val + l2->val) % 10);
		l1 = l1->next;
		l2 = l2->next;
		while(l1 != NULL && l2 != NULL)
		{
			PushBack(ret, (l1->val + l2->val + carry) % 10);
			carry = (l1->val + l2->val + carry) / 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL)
		{
			PushBack(ret, (l1->val + carry) % 10);
			carry = (l1->val + carry) / 10;
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			PushBack(ret, (l2->val + carry) % 10);
			carry = (l2->val + carry) / 10;
			l2 = l2->next;
		}
		if (carry == 1)
		{
			PushBack(ret, 1);
		}
		return ret;
    }
};
void main()
{
	Solution s;
	ListNode* l1 = new ListNode(2);
	PushBack(l1,4);
	PushBack(l1,3);
	ListNode* l2 = new ListNode(5);
	PushBack(l2,6);
	PushBack(l2,4);

	ListNode* l3 = s.addTwoNumbers(l1,l2);

	ListNode* l = l1;
	while(l != NULL)
	{
		cout<<l->val<<" ";
		l = l->next;
	}
	cout<<endl;
	l = l2;
	while(l != NULL)
	{
		cout<<l->val<<" ";
		l = l->next;
	}
	cout<<endl;
	l = l3;
	while(l != NULL)
	{
		cout<<l->val<<" ";
		l = l->next;
	}
	cout<<endl;
}