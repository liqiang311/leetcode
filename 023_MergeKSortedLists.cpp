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
//	������
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
	tmp = A[i];//���׽ڵ��ֵ
	for (; _LqLeftChild(i) < N;)
	{
		child = _LqLeftChild(i);//���ӵ�λ��
		if (child != N-1 && A[child+1] < A[child])//�����ӷ����һ��Ԫ�أ����Һ��ӵ�ֵС�����ӣ�����Һ��ӽ��д���
		{
			child++;//childָ���Һ��ӵ�λ�ã���Ϊ�Һ��ӱ�����С
		}
		if (tmp > A[child])//�����ӵ�ֵ�Ƚڵ�С���򽫺��ӵ�ֵ�Ƶ����׽ڵ㴦
		{
			A[i] = A[child];
		}
		else//˵���������Ӷ��ȸ��׽ڵ�С���������ѵ�ԭ�򣬳����������ʱiָ��
		{
			break;
		}
		i = child;//i�ɸ��׽��ָ���µĸ��׽�㣨�����ӣ�,���µĸ��׽���ֵ������tmp��
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
		//����С��
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
		//ѭ���α�����ƶ�
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