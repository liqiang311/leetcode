/* 
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //从第n个结点开始找
		ListNode *removeNodePre = head;//指向要删除的结点
		ListNode *p = head;
		while (n>0)
		{
			p = p->next;
			n--;
		}
		if (p == NULL)
		{
			ListNode* ret = head->next;
			delete head;
			return ret;
		}

		while (p->next != NULL)
		{
			p = p->next;
			removeNodePre = removeNodePre->next;
		}
		ListNode *remove = removeNodePre->next;
		removeNodePre->next = removeNodePre->next->next;
		delete remove;
		return head;
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