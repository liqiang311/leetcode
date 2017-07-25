/* 
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		for (int i=0; i<len; i++)
		{
			if (nums[i] == target)
			{
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