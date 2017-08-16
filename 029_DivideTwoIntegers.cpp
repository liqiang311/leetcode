/* 
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0)
			return INT_MAX;
		long long llDiviend = dividend;
		long long llDivisor = divisor;
		long long ret = 0;
		//判断正负
		bool isPositive = false;
		if ((llDiviend > 0 && llDivisor > 0) ||
			(llDiviend < 0 && llDivisor < 0))
			isPositive = true;
		//转变为正数求解
		llDiviend = abs(llDiviend);
		llDivisor = abs(llDivisor);
		//除法
		while (llDiviend >= llDivisor)
		{
			for (int i=0; i<=32; i++)
			{
				//左移i位,代表放大2^i倍
				if ((llDivisor << i) > llDiviend)
				{
					if (i-2 < 0)
						ret += 1;
					else
						ret += (long long)2 << (i-2);	
					llDiviend -= llDivisor << (i-1);
					break;
				}
				else if ((llDivisor << i) == llDiviend)
				{
					if (i-1 < 0)
						ret += 1;
					else
						ret += (long long)2 << (i-1);
					llDiviend -= llDivisor << i;
					break;
				}
			}
		}
		if (!isPositive)
			ret = 0 - ret;
		if (ret > INT_MAX)
			return INT_MAX;
		else if (ret < INT_MIN)
			return INT_MIN;
		else
			return ret;
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;

	t1 = clock();
	//for (int i=0; i<100; i++)
		//cout<<i<<"/2 = "<<s.divide(i,10)<<endl;
	cout<<s.divide(INT_MIN,-1)<<endl;
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}