/* 
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <ctime>
using namespace std;

class Solution {
public:
	//卡特尔树，某一个位置上满足剩余的右括号比左括号多,深搜
	void generate(vector<string> *v,string s,int leftNum, int rightNum)
	{
		if (leftNum == 0 && rightNum == 0)
		{
			v->push_back(s);
		}
		if (leftNum > 0)//剩余的左括号大于等于右括号，说明这个位置只能放左括号
		{
			generate(v,s+'(',leftNum-1,rightNum);
		}
		if (rightNum > 0 && leftNum < rightNum)//剩余的左括号小于右括号，说明这个位置可以放右括号，也可以放左括号
		{
			generate(v,s+')',leftNum,rightNum-1);
		}
	}
	vector<string> generateParenthesis(int n)
	{
		vector<string> ret;
		generate(&ret,"",n,n);
		return ret;
	}
	//递归做法，时间很长
	vector<string> generateParenthesis1(int n) {
		vector<string> ret;
		if (n == 1)
		{
			ret.push_back("()");
			return ret;
		}
		ret = generateParenthesis(n-1);
		vector<string> ret1;
		//左括弧有最多2*(n-1)种方法，所有右括弧后可放左括弧，所有左括弧后放右括弧
		for (int i=0; i<ret.size(); i++)
		{
			for (int j=0; j<2*(n-1); j++)
			{
				string v = ret[i];
				if (v[j] == ')' || j == 0)
				{
					v.insert(v.begin()+j+1,'(');
					int k = j+1;//插入左括弧的下一个位置
					for (; k< 2*n-1; k++)
					{
						if (v[k] == '(')
						{
							string vv = v;
							vv.insert(vv.begin()+k+1,')');
							ret1.push_back(vv);
						}
					}
				}
			}
		}
		//去重
		for (int i=0; i<ret1.size(); i++)
		{
			for (int j=i+1; j<ret1.size(); j++)
			{
				if (ret1[i] == ret1[j])
				{
					//删除j
					ret1.erase(ret1.begin()+j);
					j--;
				}
			}
		}

		return ret1;
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;

	t1 = clock();
	vector<string> v1 = s.generateParenthesis(2);
	for (int i=0; i<v1.size(); i++)
		cout<<v1[i]<<endl;
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}