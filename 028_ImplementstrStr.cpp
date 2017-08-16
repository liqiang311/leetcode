/* 
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int hLen = haystack.size();
		int nLen = needle.size();
		if (nLen == 0 && nLen == 0)
			return 0;
		if (nLen == 0)
			return -1;

		for (int i=0; i<hLen - nLen + 1; i++)
		{
			if (haystack[i] == needle[0])
			{
				int j;
				for (j=1; j<nLen; j++)
				{
					if (haystack[i+j] != needle[j])
						break;
				}
				if (j == nLen)
					return i;
			}
		}
		return -1;
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