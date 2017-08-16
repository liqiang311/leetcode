# -*- coding: utf-8 -*-

class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def maxVal():
            pass
        tnums = [1] + nums + [1]
        
        size = len(nums)
        tsize = size + 2
        dp = [[0 for col in range(tsize)] for row in range(tsize)]
        # 初始化dp矩阵
        # 初始化[0,0],[1,1],...,[n-1,n-1]
        for i in range(size):
            dp[i+1][i+1] = tnums[i] * tnums[i+1] * tnums[i+2]
        # 循环对矩阵赋值
        # dp[left][right] = dp[left][i-1] + dp[i+1,right] + nums[left-1]*nums[i]*nums[right+1]
        for length in range(1,size):
            for left in range(1,size):
                right = left + length
                print left,right
                if right < size+1:
                    dp[left][right] = max([dp[left][i-1]+dp[i+1][right]+tnums[left-1]*tnums[i]*tnums[right+1] for i in range(left,right+1)])
                
        for i in range(len(dp)):
            print dp[i]
        return dp[1][size]
        

t = [[3, 1, 5, 8]]
e = [167]
for i in range(len(t)):
    r = Solution().maxCoins(t[i])
    if e[i] == r:
        print t[i], 'done'
    else:
        print t[i], 'expect:', e[i], 'output:', r
