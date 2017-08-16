/* 
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.


基本字符	
I V X L C D M
相应的阿拉伯数字表示为	
1 5 10 50 100 500 1000
相同的数字连写、所表示的数等于这些数字相加得到的数、如：Ⅲ=3；
小的数字在大的数字的右边、所表示的数等于这些数字相加得到的数、 如：Ⅷ=8、Ⅻ=12；
小的数字、（限于 Ⅰ、X 和 C）在大的数字的左边、所表示的数等于大数减小数得到的数、如：Ⅳ=4、Ⅸ=9；
正常使用时、连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）；
在一个数的上面画一条横线、表示这个数扩大 1000 倍。
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		if (num < 1 || num > 3999)
			return "";
		string ret;
		int i;
		//处理千位
		for (i=0; i<num/1000; i++)
			ret.push_back('M');
		num %= 1000;
		//处理百位
		if (num >= 900)
			ret.append("CM");
		else if (num >= 500)
		{
			ret.push_back('D');
			for (i=0; i<(num-500)/100; i++)
				ret.push_back('C');
		}
		else if (num >= 400)
			ret.append("CD");
		else
		{
			for (i=0; i<num/100; i++)
				ret.push_back('C');
		}
		num %= 100;
		//处理十位
		if (num >= 90)
			ret.append("XC");
		else if (num >= 50)
		{
			ret.push_back('L');
			for (i=0; i<(num-50)/10; i++)
				ret.push_back('X');
		}
		else if (num >= 40)
			ret.append("XL");
		else
		{
			for (i=0; i<num/10; i++)
				ret.push_back('X');
		}
		num %= 10;
		//处理个位
		if (num == 9)
			ret.append("IX");
		else if (num >= 5)
		{
			ret.push_back('V');
			for (i=0; i<num-5; i++)
				ret.push_back('I');
		}
		else if (num >= 4)
			ret.append("IV");
		else
		{
			for (i=0; i<num; i++)
				ret.push_back('I');
		}
		return ret;
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;

	t1 = clock();
	cout<<s.intToRoman(9)<<endl;
	cout<<s.intToRoman(40)<<endl;
	cout<<s.intToRoman(1980)<<endl;
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}