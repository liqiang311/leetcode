/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	//O(n^2)
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ret;
		for (size_t i=0; i<nums.size()-1; i++)
		{
			for (size_t j=i+1; j<nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					ret.push_back(i+1);
					ret.push_back(j+1);
				}
			}
		}
		return ret;
	}

	//O(n),利用map的查找效率
	vector<int> twoSum1(vector<int>& nums, int target)
	{
		int i, sum;
		vector<int> res;
		map<int,int> hmap;
		for (i=0; i<nums.size(); i++)
		{
			if (!hmap.count(nums[i]))
			{
				hmap.insert(pair<int,int>(nums[i],i));
			}
			if (hmap.count(target-nums[i]))
			{
				int n = hmap[target-nums[i]];
				if (n < i)
				{
					res.push_back(n+1);
					res.push_back(i+1);
					return res;
				}
			}
		}
		return res;
	}
};

int main()
{
	int A[] = {2,7,5,11};
	int B[] = {3,2,4};
	int C[] = {-1,-2,-3,-4,-5};
	Solution s;
	vector<int> input1(A,A+4);
	vector<int> input2(B,B+3);
	vector<int> input3(C,C+5);
	//vector<int> output = s.twoSum(input1,9);
	//vector<int> output = s.twoSum(input2,6);
	vector<int> output = s.twoSum(input3,-8);
	for (vector<int>::iterator it = output.begin(); it!=output.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}
