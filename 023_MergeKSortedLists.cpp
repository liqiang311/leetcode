/* 
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
struct Int{
	int val;
	int index;

	Int& operator=(Int &value)
	{
		val = value.val;
		index = value.index;
		return *this;
	}
	bool operator<(Int &value)
	{
		return val < value.val;
	}
	bool operator>(Int &value)
	{
		return val > value.val;
	}
};
//	堆排序
#define _LqLeftChild(i) ((i<<1)+1)//2*i+1
void _LqSwap(Int *t1, Int *t2)
{
	Int tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}
void _LqMinHeap(Int A[], int i, int N)
{
	int child;
	Int tmp;
	tmp = A[i];//父亲节点的值
	for (; _LqLeftChild(i) < N;)
	{
		child = _LqLeftChild(i);//左孩子的位置
		if (child != N-1 && A[child+1] < A[child])//若左孩子非最后一个元素，且右孩子的值小于左孩子，则对右孩子进行处理
		{
			child++;//child指向右孩子的位置，因为右孩子比左孩子小
		}
		if (tmp > A[child])//若孩子的值比节点小，则将孩子的值移到父亲节点处
		{
			A[i] = A[child];
		}
		else//说明两个孩子都比父亲节点小，符合最大堆的原则，程序结束，此时i指向
		{
			break;
		}
		i = child;//i由父亲结点指向新的父亲结点（他孩子）,此新的父亲结点的值放置在tmp中
	}
	A[i] = tmp;
}
class Solution {
public:
	void Push_Back(ListNode* l, int val)
	{
		ListNode *n = new ListNode(val);
		n->next = l->next;
		l->next = n;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> pVector = lists;
		int len = lists.size();
		if (len < 1)
			return NULL;
		ListNode* head = new ListNode(0);
		ListNode* pRet = head;
		//建最小堆
		Int *heap = new Int[len];
		for (int i=0,j=0; i<len; i++,j++)
		{
			if (pVector[j])
			{
				Int tmp;
				tmp.val = pVector[j]->val;
				tmp.index = j;
				heap[i] = tmp;
			}
			else
			{
				i-- ;
				len --;
			}
		}
		for (int i=len/2; i>=0; i--)
		{
			_LqMinHeap(heap, i, len);
		}
		//循环游标向后移动
		while (len > 0)
		{
			int val = heap[0].val;
			Push_Back(pRet,val);
			pRet = pRet->next;
			pVector[heap[0].index] = pVector[heap[0].index]->next;
			if (pVector[heap[0].index] != NULL)
			{
				heap[0].val = pVector[heap[0].index]->val;
			}
			else
			{
				_LqSwap(&heap[0],&heap[len-1]);
				len --;
			}
			_LqMinHeap(heap, 0, len);
		}
		ListNode* ret = head->next;
		delete[] head;
		return ret;
    }
};

void main()
{
	Solution s;
	clock_t t1,t2;
	ListNode *l;
	vector<ListNode*> list;
	//l=new ListNode(1);
	list.push_back(NULL);
	l=new ListNode(2);
	list.push_back(l);
	t1 = clock();
	s.mergeKLists(list);
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}