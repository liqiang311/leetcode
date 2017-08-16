/* 

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		ListNode* listHead = new ListNode(0);
		listHead->next = head;
		if (head == NULL)
			return NULL;
        ListNode *o = listHead,*p = head, *q = head->next;
		if (q == NULL)
			return head;
		while(p!=NULL && q!=NULL)
		{
			p->next = q->next;
			q->next = p;
			o->next = q;
			o = p;
			p = o->next;
			if (p == NULL)
				break;
			q = p->next;
		}
		ListNode* ret = listHead->next;
		delete[] listHead;
		return ret;
    }
};

void main()
{
	Solution s;
	clock_t t1,t2;

	t1 = clock();

	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}