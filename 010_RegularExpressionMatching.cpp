/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) 
	{
		return isMatch1(&s[0],&p[0]);
	}

	bool isMatch1(char *s, char *p)
	{
		int sLen = strlen(s);
		int pLen = strlen(p);
		//观察两个字符串是否同时结束，若结束，返回成功，否则失败
		if (*p == '\0')
			return *s == '\0';
		if (*(p+1) == '*')//模式串下一个字符为*
		{
			//若当前字符相同或者模式字符为。且s没结束
			while (*p == *s || (*p == '.' && *s != '\0'))
			{
				//字符串与模式串匹配0/1/2...个字符的情况 
				if (isMatch1(s++,p+2))
					return true;
			}
			return isMatch1(s,p+2);
		}
		else
		{
			 if (*p == *s || (*p == '.' && *s != '\0'))  
				return isMatch1(s+1,p+1);
			  return false;  
		}
	}
};

void main()
{
	Solution s;
	cout<<s.isMatch("aa","a")<<endl;// → false
	cout<<s.isMatch("aa","aa")<<endl;// → true
	cout<<s.isMatch("aaa","aa")<<endl;// → false
	cout<<s.isMatch("aa", "a*")<<endl;// → true
	cout<<s.isMatch("aa", ".*")<<endl;// → true
	cout<<s.isMatch("ab", ".*")<<endl;// → true
	cout<<s.isMatch("aab", "c*a*b")<<endl;// → true
	cout<<s.isMatch("ab", ".*c")<<endl;// → false
	cout<<s.isMatch("aaa", "aaaa")<<endl;// → false
	cout<<s.isMatch("aaa","ab*ac*a")<<endl;// true
}