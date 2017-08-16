/* 
Write a function to find the longest common prefix string amongst an array of strings.

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution 
{
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ret;
		int len = strs.size();
		if (len == 0)
			return ret;
		if (len == 1)
			return strs[0];
		int index = 0;
		while(1)
		{
			if (index >= strs[0].size())
				return ret;
			char c = strs[0][index];
			for (int i=1; i<len; i++)
			{

				if (index >= strs[i].size() || c != strs[i][index])
					return ret;
			}
			ret.push_back(c);
			index ++;
		}
		return ret;
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