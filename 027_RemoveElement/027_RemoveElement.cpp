/* 
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		for (int i=0; i<len; i++)
		{
			if (nums[i] == val)
			{
				int tmp = nums[i];
				nums[i] = nums[len-1];
				nums[len-1] = tmp;
				len --;
				i--;
			}
		}
		return len;
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