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
	//���ض�����ĳһ��λ��������ʣ��������ű������Ŷ�,����
	void generate(vector<string> *v,string s,int leftNum, int rightNum)
	{
		if (leftNum == 0 && rightNum == 0)
		{
			v->push_back(s);
		}
		if (leftNum > 0)//ʣ��������Ŵ��ڵ��������ţ�˵�����λ��ֻ�ܷ�������
		{
			generate(v,s+'(',leftNum-1,rightNum);
		}
		if (rightNum > 0 && leftNum < rightNum)//ʣ���������С�������ţ�˵�����λ�ÿ��Է������ţ�Ҳ���Է�������
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
	//�ݹ�������ʱ��ܳ�
	vector<string> generateParenthesis1(int n) {
		vector<string> ret;
		if (n == 1)
		{
			ret.push_back("()");
			return ret;
		}
		ret = generateParenthesis(n-1);
		vector<string> ret1;
		//�����������2*(n-1)�ַ�����������������ɷ����������������������������
		for (int i=0; i<ret.size(); i++)
		{
			for (int j=0; j<2*(n-1); j++)
			{
				string v = ret[i];
				if (v[j] == ')' || j == 0)
				{
					v.insert(v.begin()+j+1,'(');
					int k = j+1;//��������������һ��λ��
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
		//ȥ��
		for (int i=0; i<ret1.size(); i++)
		{
			for (int j=i+1; j<ret1.size(); j++)
			{
				if (ret1[i] == ret1[j])
				{
					//ɾ��j
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