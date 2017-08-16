/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int length1 = nums1.size();
		int length2 = nums2.size();
		int p1 = 0, p2 = 0;
		int preNum = 0;
		while(p1+p2 < (length1+length2)/2 && p1 < length1 && p2 < length2)
		{
			if (nums1[p1] < nums2[p2])
			{
				preNum = nums1[p1];
				p1++;
			}
			else
			{
				preNum = nums2[p2];
				p2++;
			}
		}
		while(p1 < length1 && p1+p2 < (length1+length2)/2)
		{
			preNum = nums1[p1];
			p1++;
		}
		while(p2 < length2 && p1+p2 < (length1+length2)/2)
		{
			preNum = nums2[p2];
			p2++;
		}
		int minNum;
		if (p1 == length1)
			minNum = nums2[p2];
		else if (p2 == length2)
			minNum = nums1[p1];
		else
			minNum = min(nums1[p1],nums2[p2]);
		if ((length1+length2) % 2 == 0)
			return (minNum+preNum)/2.0;
		else
			return minNum;
	}

	double findKth(int *v1, int length1, int *v2, int length2, int k)
	{
		//确保v1规模小于v2
		if (length1 > length2)
			return findKth(v2,length2,v1,length1,k);
		//v1的尺寸为0，返回v2里第K个数
		if (length1 == 0)
			return v2[k-1];
		if (k == 1)
			return min(v1[0], v2[0]);
		//否则比较
		int n1 = min(length1, k/2);
		int n2 = k - n1 ;
		if (v1[n1-1] < v2[n2-1])
			return findKth(v1+n1,length1-n1,v2,length2,k-n1);
		else if (v1[n1-1] > v2[n2-1])
			return findKth(v1,length1,v2+n2,length2-n2,k-n2);
		else
			return v1[n1-1];
	}

	double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2)
	{
		int length1 = nums1.size();
		int length2 = nums2.size();
		if ((length1+length2) % 2 == 1)
			return findKth(&nums1[0],length1,&nums2[0],length2,(length1+length2)/2+1);
		else
			return (findKth(&nums1[0],length1,&nums2[0],length2,(length1+length2)/2) + 
					findKth(&nums1[0],length1,&nums2[0],length2,(length1+length2)/2+1) ) / 2.0;

	}
};

int main()
{
	int A[] = {3,4,5,6};
	vector<int> v1(A,A+4);
	int B[] = {1,2};
	vector<int> v2(B,B+2);
	vector<int> v3;
	Solution s;
	cout<<s.findMedianSortedArrays(v1,v2)<<endl;
	cout<<s.findMedianSortedArrays1(v1,v2)<<endl;
	return 0;
}

/*
//若两个合并是有序序列
if (nums1[length1 - 1] < nums2[0])
{
if (length1 > length2)
return (nums1[(length1+length2)/2] + nums1[(length1+length2-1)/2])/2.0;
else
return (nums2[(length1+length2)/2-length1] + nums2[(length1+length2-1)/2-length1])/2.0;
}
else if (nums2[length2 - 1] < nums1[0])
{
if (length2 > length1)
return (nums2[(length1+length2)/2]+nums2[(length1+length2-1)/2])/2.0;
else
return (nums1[(length1+length2)/2-length2]+nums1[(length1+length2-1)/2-length2])/2.0;
}
*/