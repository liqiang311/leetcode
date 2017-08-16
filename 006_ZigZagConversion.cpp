/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

0	 	 	 	8	 	 	 	16	 	 	 
1	 	 	7	9	 	 	15	17	 	 	 
2	 	6	 	10	 	14	 	18	 	 	 
3	5	 	 	11	13	 	 	19	 	 	 
4	 	 	 	12	 	 	 	20	

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows < 2 || s.size() <= numRows)
			return s;
		string ret;
		int length = s.size();
		int numInGroup = 2 * numRows - 2;
		int groupNum = length / numInGroup;//组数
		int extendNum = length % numInGroup;//多余的数目
		int i, j;
		for (i=0; i<numRows; i++)
		{
			for (j=0; j<groupNum; j++)
			{
				if (j*numInGroup+i < length)
					ret.push_back(s[j*numInGroup+i]);
				if (i != 0 && i != numRows-1 && j*numInGroup+numInGroup-i < length)
					ret.push_back(s[j*numInGroup+numInGroup-i]);
			}
			if (extendNum <= numRows && extendNum > 0 && groupNum*numInGroup+i < length)
				ret.push_back(s[groupNum*numInGroup+i]);
			else if (extendNum > numRows && groupNum*numInGroup+i < length)
			{
				ret.push_back(s[groupNum*numInGroup+i]);
				if (i != 0 && i != numRows-1 && extendNum - numRows >= numRows - i - 1 && groupNum*numInGroup+numInGroup-i < length)
					ret.push_back(s[groupNum*numInGroup+numInGroup-i]);
			}
			
		}
		return ret;
	}
};


int main()
{

	Solution s;
	string s1 = "PAYPALISHIRING";
	string s2 = "AB";
	string s3 = "ABCDE";
	string s4 = "ABC";
 	cout<<s.convert(s1,9)<<endl;
 	cout<<"PAYPGANLIIRSIH"<<endl;
// 	cout<<s.convert(s2,1)<<endl;
//	cout<<s.convert(s3,4)<<endl;
//	cout<<s.convert(s4,2)<<endl;
	return 0;
}