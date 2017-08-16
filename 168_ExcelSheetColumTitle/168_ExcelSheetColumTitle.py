class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        r = ''
        while(n):
            mod = n % 26
            if mod == 0:
                mod = 26
                n -= 26
            n /= 26;
            r += chr(ord('A')-1+mod)
        r = r[::-1]
        return r
            
        
test = [1,26,27,52,701]
expect = ['A','Z','AA','AZ','ZY']
for i in range(len(test)):
    res = Solution().convertToTitle(test[i])
    if res == expect[i]:
        print test[i], "done"
    else:
        print test[i], "expect:", expect[i], "output:", res
