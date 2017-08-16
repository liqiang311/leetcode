/* 
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

const char Map[10][5] = {"","","abc","def",	"ghi","jkl","mno","pqrs","tuv","wxyz"};
const int MapSize[10] = {0,0,3,3,3,3,3,4,3,4};

class Solution {
public:

	vector<string> letterCombinations(string digits) {
		vector<string> ret1,ret2;
		int len = digits.size();
		int index;
		if (len < 1)
			return ret1;
		for (int i=0; i<len; i+=2)
		{
			index = digits[i] - '0';
			if (index < 0 || index > 9 || index == 0 || index == 1)
				continue;
			for (int k=0; k<MapSize[index]; k++)
			{
				if (ret1.size() == 0)
				{
					string s;
					s.push_back(Map[index][k]);
					ret2.push_back(s);
				}
				for (int j=0; j<ret1.size(); j++)
				{
					string s = ret1[j];
					string s1 = s;
					s1.push_back(Map[index][k]);
					ret2.push_back(s1);
				}
			}
			ret1.clear();
			if ( i == len-1 )
				return ret2;
			index = digits[i+1] - '0';
			if (index < 0 || index > 9 || index == 0 || index == 1)
				continue;
			for (int k=0; k<MapSize[index]; k++)
			{
				if (ret2.size() == 0)
				{
					string s;
					s.push_back(Map[index][k]);
					ret1.push_back(s);
				}
				for (int j=0; j<ret2.size(); j++)
				{
					string s = ret2[j];
					string s1 = s;
					s1.push_back(Map[index][k]);
					ret1.push_back(s1);
				}
			}
			ret2.clear();
		}
		return ret1;
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;

	t1 = clock();
	vector<string> v = s.letterCombinations("23");
	for (int i=0; i<v.size(); i++)
		cout<<v[i]<<endl;
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}