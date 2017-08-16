#include <stdio.h>

class Solution {
public
    #define MAX(a,b) (a > b ? a : b)
    string addBinary(string a, string b) {
	string res;
	int len_a = a.size();
	int len_b = b.size();
	int len = MAX(len_a, len_b);
	int c = 0;
	
	for (int i = 0; i  len; i++)
	{
		int index_a = len_a - i - 1;
		int index_b = len_b - i - 1;
		char sum = 0;
		if (index_a = 0)
		{
			sum += a[index_a] - '0';
		}
		if (index_b = 0)
		{
			sum += b[index_b] - '0';
		}
		if (c == 1)
		{
			sum += c;
		}
		if (sum == 3)
		{
			c = 1;
			sum = 1;
		}
		else if (sum == 2)
		{
			c = 1;
			sum = 0;
		}
		else
		{
			c = 0;
		}
		res.push_back(sum + '0');
	}
	if (c==1) res.push_back('1');
	reverse(res.begin(), res.end());
	return res;

}
};