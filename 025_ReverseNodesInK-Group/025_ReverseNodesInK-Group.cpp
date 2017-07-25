/* 
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
		if (k < 2)
			return head;
		//加一头结点
		ListNode* listHead = new ListNode(0);
		listHead->next = head;
		if (head == NULL)
			return NULL;
		//每个结点的指针
        ListNode **pNode = new ListNode *[k+1];
		//初始化每个指针
		ListNode *p = listHead;
		for (int i=0; i<k+1; i++)
		{
			if (p == NULL)
				return head;
			pNode[i] = p;
			p = p->next;
		}
		while(1)
		{
			int i;
			//颠倒
			pNode[0]->next = pNode[k];
			pNode[1]->next = pNode[k]->next;
			for (i=2; i<k+1; i++)
				pNode[i]->next = pNode[i-1];
			//赋新值
			pNode[0] = pNode[1];
			for (i=1; i<k+1; i++)
			{
				pNode[i] = pNode[i-1]->next;
				if (pNode[i] == NULL)
					break;
			}
			if (i != k+1)
				break;
		}
		ListNode* ret = listHead->next;
		delete[] listHead;
		delete[] pNode;
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