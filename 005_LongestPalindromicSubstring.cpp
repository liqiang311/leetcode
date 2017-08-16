/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string *s, int start, int end)
	{
		int length = end - start + 1;
		if (length == 1)
			return true;
		if (length > 4)
		{
			int i;
			for (i=0; i<length/4; i++)
			{
				if ((*s)[start+i] != (*s)[end-i])
				{
					return false;
				}
				if ((*s)[start+length/2-i] != (*s)[end-length/2+i])
				{
					return false;
				}
			}
			for (; i<length/2; i++)
			{
				if ((*s)[start+i] != (*s)[end-i])
				{
					return false;
				}
			}
		}
		else
		{
			for (int i=0; i<length/2; i++)
			{
				if ((*s)[start+i] != (*s)[end-i])
				{
					return false;
				}
			}
		}
		return true;
	}
	//暴力破解O(n^3)
	string longestPalindrome(string s) {
		int length = s.size();
		if (length > 1000)
			return string("");
		int subLength = length;
		while (subLength > 0)
		{
			for (int i=0; i<=length-subLength; i++)
			{
				if (isPalindrome(&s,i,i+subLength-1))
					return s.substr(i,subLength);
			}
			subLength --;
		}
		return string("");
	}
	//动态规划O(n^2)
	string longestPalindrome1(string s) {
		int length = s.size();
		if (length > 1000)
			return string("");
		bool mark[1000][1000];//标记从i到j这段序列是否为回文序列
		memset(mark,false,sizeof(mark));
		//初始化序列
		//自己到自己肯定是回文
		for (int i=0; i<length; i++)
			mark[i][i] = true;
		//两个字符是否是回文取决于
		for (int i=0; i<length-1; i++)
		{
			mark[i][i+1] = (s[i] == s[i+1]);
			mark[i+1][i] = (s[i] == s[i+1]);
		}
		int maxStart = 0;
		int maxLength = 1;
		for (int len=2; len<=length; len++)
		{
			for (int i=0; i<=length-len; i++)
			{
				if (s[i] == s[i+len-1] && mark[i+1][i+len-2])
				{
					maxStart = i;
					maxLength = len;
					mark[i][i+len-1] = true;
				}
			}
		}
		return s.substr(maxStart,maxLength);
	}
	//基于中心点向外扩张，看是否为回文序列,c1c2为扩张左右jie，startlen为扩张后的起点和长度
	void ExpandAroundCenter(string *s,int c1,int c2,int *start,int *len)
	{
		*start = c1;
		*len = c2 - c1 + 1;
		while (c1 >=0 && c2 < (*s).size() && (*s)[c1] == (*s)[c2])
		{
			c1 --;
			c2 ++;
		}
		*start = c1 + 1;
		*len = c2  - c1 - 1;
	}
	//中心检测法O(n^2)
	string longestPalindrome2(string s) 
	{
		int size = s.size();
		int maxStart = 0,maxLenth = 0;
		int start,length;

		for (int i=0; i<size; i++)
		{
			ExpandAroundCenter(&s,i,i,&start,&length);
			if (length > maxLenth)
			{
				maxLenth = length;
				maxStart = start;
			}
		}
		for (int i=0; i<size-1; i++)
		{
			ExpandAroundCenter(&s,i,i+1,&start,&length);
			if (length > maxLenth)
			{
				maxLenth = length;
				maxStart = start;
			}
		}
		return s.substr(maxStart,maxLenth);
	}
	//Manacher算法O(n)
	string longestPalindrome3(string s) 
	{

	}
};

int main()
{
	Solution s;
	string s1 = "abcdedcba22222";
	string s2 = "kztakrekvefgchersuoiuatzlmwynzjhdqqftjcqmntoyckqfawikkdrnfgbwtdpbkymvwoumurjdzygyzsbmwzpcxcdmmpwzmeibligwiiqbecxwyxigikoewwrczkanwwqukszsbjukzumzladrvjefpegyicsgctdvldetuegxwihdtitqrdmygdrsweahfrepdcudvyvrggbkthztxwicyzazjyeztytwiyybqdsczozvtegodacdokczfmwqfmyuixbeeqluqcqwxpyrkpfcdosttzooykpvdykfxulttvvwnzftndvhsvpgrgdzsvfxdtzztdiswgwxzvbpsjlizlfrlgvlnwbjwbujafjaedivvgnbgwcdbzbdbprqrflfhahsvlcekeyqueyxjfetkxpapbeejoxwxlgepmxzowldsmqllpzeymakcshfzkvyykwljeltutdmrhxcbzizihzinywggzjctzasvefcxmhnusdvlderconvaisaetcdldeveeemhugipfzbhrwidcjpfrumshbdofchpgcsbkvaexfmenpsuodatxjavoszcitjewflejjmsuvyuyrkumednsfkbgvbqxfphfqeqozcnabmtedffvzwbgbzbfydiyaevoqtfmzxaujdydtjftapkpdhnbmrylcibzuqqynvnsihmyxdcrfftkuoymzoxpnashaderlosnkxbhamkkxfhwjsyehkmblhppbyspmcwuoguptliashefdklokjpggfiixozsrlwmeksmzdcvipgkwxwynzsvxnqtchgwwadqybkguscfyrbyxudzrxacoplmcqcsmkraimfwbauvytkxdnglwfuvehpxd";
	string s3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string s4 = "aaaabaaa";
	//cout<<s.longestPalindrome(s1)<<endl;
	clock_t t1,t2;
	t1 = clock();
	//cout<<s.longestPalindrome(s2)<<endl;
	//cout<<s.longestPalindrome(s3)<<endl;
	t2 = clock();
	//cout<<t2-t1<<endl;
	//cout<<s.longestPalindrome1(s4)<<endl;
	cout<<s.longestPalindrome2(s3)<<endl;
	return 0;
}