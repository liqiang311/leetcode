# -*- coding: utf-8 -*-
# 一个一个序列,后一个序列是对前一个序列的描述

class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        pre = ""
        res = "1"
        for i in range(n-1):
            pre = res
            res = ""
            start = 0
            ch_temp = pre[0]
            for j, ch in enumerate(pre):
                if ch != ch_temp:
                    count = j - start
                    res = res + str(count) + ch_temp
                    start = j
                    ch_temp = ch
                if  j == len(pre)-1:
                    count = j - start + 1
                    res = res + str(count) + ch_temp
            #print res
        return res

print Solution().countAndSay(5)
