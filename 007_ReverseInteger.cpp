#include <iostream>
using namespace std;


class Solution {
public:
	int reverse(int x) {
		long long X = x;
		int radio;
		int ret = 0;
		if (X > 0)
			radio = 1;
		else
		{
			radio = -1;
			X *= -1;
		}

		int tmp = X % 10;
		ret += tmp;
		X = X / 10;
		while (X > 0)
		{
			tmp = X % 10;
			if (ret > INT_MAX/10)
				return 0;
			ret *= 10;
			ret += tmp;
			X = X / 10;
		}
		return ret*radio;
	}
	//有问题代码，未处理溢出
	int reverse1(int x)
	{
		bool is_pos = x > 0;
		x = abs(x);
		long long result = 0;
		while (x >= 1) { //逐个地处理x的个位，十位，百位...
			result = result * 10 + x % 10; //注意求个位可以用%，不用像上面那么麻烦。
			x = x / 10;
		}
		if (result > INT_MAX)
			return 0;
		if (is_pos) return result;
		else return -result;
	}
};


void main()
{
	Solution s;
// 	cout<<s.reverse(-123)<<endl;
// 	cout<<s.reverse(1534236469)<<endl;
	cout<<s.reverse1(1534236469)<<endl;
}