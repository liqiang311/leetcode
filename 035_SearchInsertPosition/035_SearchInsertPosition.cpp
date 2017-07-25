/* 
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 �� 2
[1,3,5,6], 2 �� 1
[1,3,5,6], 7 �� 4
[1,3,5,6], 0 �� 0

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int size = nums.size();
		for (int i=0; i<size; i++)
		{
			if (target <= nums[i])
				return i;
		}
		return size;
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