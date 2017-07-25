/* 
Given a string containing just the characters
'(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, 
"()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <ctime>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> character;
		int len = s.size();
		for (int i=0; i<len; i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				character.push(s[i]);
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (character.empty())
					return false;
				char c = character.top();
				if ((s[i] == ')' && c != '(') ||
					(s[i] == ']' && c != '[') ||
					(s[i] == '}' && c != '{'))
					return false;
				character.pop();
			}
		}
		if (character.empty())
			return true;
		else
			return false;
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