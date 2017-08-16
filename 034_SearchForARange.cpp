/* 
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		int pos = Search(&nums[0],0,nums.size()-1,target);
		ret.push_back(pos);
		ret.push_back(pos);
		if (pos >= 0)
		{
			//ÍùÇ°
			while(ret[0] > 0 && nums[ret[0]-1] == target)
			{
				ret[0] --;
			}
			//Íùºó
			while(ret[1] < nums.size()-1 && nums[ret[1]+1] == target)
			{
				ret[1] ++;
			}
		}
		return ret;
	}
	int Search(int *nums, int start, int end,int target)
	{
		if (start > end) return -1;
		int pos = (start + end) / 2;
		if (nums[pos] == target) return pos;
		else if (nums[pos] < target) return Search(nums,pos+1,end,target);
		else return Search(nums,start,pos-1,target);
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;
	int a[] = {0,0,0,1,2,3};
	vector<int> v(a,a+6);
	vector<int> ret;
	t1 = clock();
	ret = s.searchRange(v,0);
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}