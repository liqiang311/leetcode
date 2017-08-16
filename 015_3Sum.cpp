/* 
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)

*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <algorithm>
//#include <functional>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end(),less<int>());
		return KSum(&nums[0],nums.size(),0,3);
	}
	vector<vector<int>> KSum(int nums[], int size, int target, int k) {
		vector<vector<int>> ret;
		if (k < 2)
			return ret;
		if (k == 2)
		{
			int start = 0;
			int end = size-1;
			int preStart = INT_MAX, preEnd = INT_MAX;
			while (start < end)
			{
				if (nums[start] + nums[end] == target)
				{
					if (preStart != nums[start] || preEnd != nums[end])
					{
						vector<int> v;
						v.push_back(nums[start]);
						v.push_back(nums[end]);
						ret.push_back(v);
						preStart = nums[start];
						preEnd = nums[end];
					}
					start ++;
					end --;
				}
				else if (nums[start] + nums[end] < target)
					start ++;
				else
					end --;
			}
			return ret;		
		}
		for (int i=0; i<size-2; i++)
		{
			if (i != 0 && nums[i] == nums[i-1])
				continue;
			vector<vector<int>> ret1 = KSum(nums+i+1,size-i-1,target-nums[i], k-1);
			for (int j=0; j<ret1.size(); j++)
			{
				ret1[j].insert(ret1[j].begin(),nums[i]);
				ret.push_back(ret1[j]);
			}
		}
		return ret;
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;

	int A[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> AA(A, A+sizeof(A)/sizeof(int));

	t1 = clock();
	vector<vector<int>> ret = s.threeSum(AA);
	for (int i=0; i<ret.size(); i++)
	{
		for (int j=0; j<ret[i].size(); j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}