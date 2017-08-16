/* 
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.


I V X L C D M
相应的阿拉伯数字表示为	
1 5 10 50 100 500 1000
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution 
{
public:
	int romanToInt(string s) {
		int ret = 0;
		int len = s.size();
		int i = 0;
		while (i < len)
		{
			if (s[i] == 'M')
			{
				ret += 1000;
				i++;
			}
			else if (s[i] == 'C')
			{
				if (i < len-1 && s[i+1] == 'M')
				{
					ret += 900;
					i += 2;
				}
				else if (i < len-1 && s[i+1] == 'D')
				{
					ret += 400;
					i += 2;
				}
				else
				{
					ret  += 100;
					i ++;
				}
			}
			else if (s[i] == 'L')
			{
				ret += 50;
				i ++;
			}
			else if (s[i] == 'D')
			{
				ret += 500;
				i ++;
			}
			else if (s[i] == 'X')
			{
				if (i < len-1 && s[i+1] == 'C')
				{
					ret += 90;
					i += 2;
				}
				else if (i < len-1 && s[i+1] == 'L')
				{
					ret += 40;
					i += 2;
				}
				else
				{
					ret  += 10;
					i ++;
				}
			}
			else if (s[i] == 'V')
			{
				ret += 5;
				i++;
			}
			else if (s[i] == 'I')
			{
				if (i < len-1 && s[i+1] == 'X')
				{
					ret += 9;
					i += 2;
				}
				else if (i < len-1 && s[i+1] == 'V')
				{
					ret += 4;
					i += 2;
				}
				else
				{
					ret  ++;
					i ++;
				}
			}
			else
				return 0;
		}
		return ret;
	}
	//I V  X L   C   D    M
	//1 5 10 50 100 500 1000
};

void main()
{
	Solution s;
	clock_t t1,t2;

	t1 = clock();
	cout<<s.romanToInt("MCMLXXX")<<endl;
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}