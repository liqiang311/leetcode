/* 
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,	Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 

It doesn't matter what you leave beyond the new length.
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i;
		int ret = 1;
		int len = nums.size();
		if (len < 1)
			return 0;
		for (int i=1; i<len; i++)
		{
			if (nums[i] != nums[i-1])
			{
				nums[ret++] = nums[i];
			}
		}
		return ret;
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;
	int A[] = {1,2};
	vector<int> AA(A,A+2);
	t1 = clock();
	cout<<s.removeDuplicates(AA)<<endl;
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}