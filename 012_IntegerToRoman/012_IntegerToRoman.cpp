/* 
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.


�����ַ�	
I V X L C D M
��Ӧ�İ��������ֱ�ʾΪ	
1 5 10 50 100 500 1000
��ͬ��������д������ʾ����������Щ������ӵõ��������磺��=3��
С�������ڴ�����ֵ��ұߡ�����ʾ����������Щ������ӵõ������� �磺��=8����=12��
С�����֡������� ��X �� C���ڴ�����ֵ���ߡ�����ʾ�������ڴ�����С���õ��������磺��=4����=9��
����ʹ��ʱ����д�������ظ����ó������Ρ��������ϵ��ĵ��ӡ�IIII�����⣩��
��һ���������滭һ�����ߡ���ʾ��������� 1000 ����
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
		//����ǧλ
		for (i=0; i<num/1000; i++)
			ret.push_back('M');
		num %= 1000;
		//�����λ
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
		//����ʮλ
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
		//�����λ
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