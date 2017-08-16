# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

version = "0000011"

def isBadVersion(n):
    if version[n-1] == '1':
        return True
    else:
        return False

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = 1
        right = n
        while left <= right:
            middle = (left+right)/2
            isbad = isBadVersion(middle)
            if isbad:
                right = middle - 1
            else:
                left = middle + 1
        return left

print Solution().firstBadVersion(len(version))
