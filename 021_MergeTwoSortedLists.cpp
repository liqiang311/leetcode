/* 

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
	void Insert(ListNode* l1 ,ListNode* l2)//l2插到l1的后面
	{
		l2->next = l1->next;
		l1->next = l2;
	}
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);
		head->next = l1;
        ListNode *p1 = head, *p2 = l2;
		while (p1->next != NULL && p2 != NULL)
		{
			if (p1->next->val < p2->val)
			{
				p1 = p1->next;
			}
			else
			{
				ListNode *tmp = p2->next;
				Insert(p1,p2);
				p2 = tmp;
			}
		}
		while(p2 != NULL)
		{
			ListNode *tmp = p2->next;
			Insert(p1,p2);
			p2 = tmp;
			p1 = p1->next;
		}
		ListNode *ret = head->next;
		delete[] head;
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