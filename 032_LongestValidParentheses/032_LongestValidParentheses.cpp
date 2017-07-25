/* 
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stack>
using namespace std;

class Solution {
public:
	int longestValidParentheses1(string s)
	{
		int len = s.size();
		int ret = 0;
		//�������
		char *mark = new char[len];
		memset(mark,0,len);

		int leftNum = 0, rightNum = 0;
		for (int i=0; i<len; i++)
		{
			leftNum = 0;
			rightNum = 0;
			for (int j=i; j<len; j++)
			{
				if (s[j] == '(')
					leftNum++;
				else
					rightNum++;
				if (leftNum < rightNum)
					break;
				else if (leftNum == rightNum)
				{
					for (int k=i; k<=j; k++)
						mark[k] = 1;
					i = j;
					break;
				}
			}
		}
		//�Ա��������д���,�������
		int tmp = 0;
		for (int i=0; i<len; i++)
		{
			if (mark[i])
			{
				tmp ++;
				ret = max(tmp, ret);
			}
			else
				tmp = 0;
		}
		return ret;        
	}
	int longestValidParentheses(string s)
	{
		int len = s.size();
		int ret = 0;
		int preRight = -1;//��һ�������ŵ�λ��
		//�������
		char *mark = new char[len];
		memset(mark,0,len);

		for (int i=1; i<len; i++)
		{
			if (s[i] == ')')
			{
				if (i-preRight >= 2 && s[i-1] == '(')//��������ź�ǰһ�������ž�2 �����м���������
				{
					mark[i] = mark[i-1] = 1;
				}
				else if (i-preRight == 1)//���ڣ���ǰ�ߣ��ҵ��Ǳ�ǵ����������ţ�����
				{
					int j = preRight;
					while(mark[j] == 1)
						j --;
					if (j >= 0 && s[j] == '(')
						mark[j] = mark[i] = 1;
				}

				preRight = i;
			}
		}
		//�Ա��������д���,�������
		int tmp = 0;
		for (int i=0; i<len; i++)
		{
			if (mark[i])
			{
				tmp ++;
				ret = max(tmp, ret);
			}
			else
				tmp = 0;
		}
		return ret;    
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;

	t1 = clock();
	cout<<s.longestValidParentheses(")()())")<<endl;
	cout<<s.longestValidParentheses("()(()")<<endl;
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}