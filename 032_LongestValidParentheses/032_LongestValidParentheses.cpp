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
		//标记数组
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
		//对标记数组进行处理,计算最长的
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
		int preRight = -1;//上一个右括号的位置
		//标记数组
		char *mark = new char[len];
		memset(mark,0,len);

		for (int i=1; i<len; i++)
		{
			if (s[i] == ')')
			{
				if (i-preRight >= 2 && s[i-1] == '(')//这个右括号和前一个右括号距2 表明中间是左括号
				{
					mark[i] = mark[i-1] = 1;
				}
				else if (i-preRight == 1)//相邻，往前走，找到非标记的若是左括号，则标记
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
		//对标记数组进行处理,计算最长的
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