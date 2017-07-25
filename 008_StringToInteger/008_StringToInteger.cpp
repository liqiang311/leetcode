#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) 
	{
		//去除非数字字符
		string s;
		bool b = false;
		int radio = 1;
		for (size_t i=0; i<str.size(); i++)
		{
			if (str[i] == ' ')
			{
				if (b)	break;
				continue;
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				if (b)	return 0;
				b = true;
				if (str[i] == '-')
					radio = -1;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				b = true;
				s.push_back(str[i]);
			}
			else
			{
				break;
			}
		}
		//转化
		int length = s.size();
		long long ret = 0;
		for (int i=length-1; i>=0; i--)
		{
			long long tmp = 1;
			for (int k=i; k<length-1; k++)
				tmp *= 10;
			ret += tmp * (s[i]-'0');
			if (ret * radio > (long long)2147483647)
				return 2147483647;
			if (ret * radio < (long long)(-2147483647 - 1))
				return (-2147483647 - 1);
		}
		
		return ret * radio;
	}
};

void main()
{
	Solution s;
	cout<<s.myAtoi("2147483648")<<endl;
}