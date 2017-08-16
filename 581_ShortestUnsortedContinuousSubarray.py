import copy

class Solution(object):

    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sorted_arr = copy.deepcopy(nums)
        sorted_arr.sort()
        length = len(nums)
        left = 0
        for i in range(len(nums)):
            left = i
            if sorted_arr[i] == nums[i]:
                length -= 1
            else:
                break
        for i in range(len(nums)-1, left, -1):
            if sorted_arr[i] == nums[i]:
                length -= 1
            else:
                break
        return length

    # 318ms
    def findUnsortedSubarray1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sorted_arr = copy.deepcopy(nums)
        sorted_arr.sort()
        length = len(nums)
        left = 0
        for i in range(len(nums)):
            left = i
            if sorted_arr[i] == nums[i]:
                length -= 1
            else:
                break
        for i in range(len(nums)-1, left, -1):
            if sorted_arr[i] == nums[i]:
                length -= 1
            else:
                break
        return length



print Solution().findUnsortedSubarray([2, 6, 4, 8, 10, 9, 15])
print Solution().findUnsortedSubarray([1,2,3,4])
