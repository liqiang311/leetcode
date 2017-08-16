/* 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//从后向前扫描,找到一个比最后一个小的,若没有从第二个开始找
		int len = nums.size();
		int i,j;
		for (i=len-2; i>=0; i--)
			if (nums[i] < nums[i+1])
				break;
		for (j=len-1; j>i; j--)
			if (nums[i] < nums[j])
				break;
		if (i >= 0)
		{
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
		reverse(nums.begin()+i+1,nums.end());
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;
	int A[] = {1,2};
	vector<int> v(A,A+3);
	t1 = clock();
	s.nextPermutation(v);
	for (int i=0; i<v.size(); i++)
		cout<<v[i]<<" ";
	cout<<endl;
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}