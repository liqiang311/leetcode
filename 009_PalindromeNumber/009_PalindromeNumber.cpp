#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		long long reserse = 0;
		int tmp = x;
		reserse += tmp % 10;
		tmp /= 10;
		while(tmp > 0)
		{
			reserse *= 10;
			reserse += tmp % 10;
			tmp /= 10;
		}
		return (reserse == x);
	}
};

void main()
{
	Solution s;
	cout<<s.isPalindrome(121)<<endl;
}
