import sys

class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.minNum = sys.maxint

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if isinstance(x, int):
            self.stack.append(x)
            if x < self.minNum:
                self.minNum = x        

    def pop(self):
        """
        :rtype: void
        """
        x = self.stack.pop()
        if x == self.minNum:
            self.minNum = sys.maxint
            for i in self.stack:
                if i < self.minNum:
                    self.minNum = i

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.minNum
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

obj = MinStack()
obj.push(-2)
obj.push(0)
obj.push(-3)
print obj.getMin()
obj.pop()
print obj.top()
print obj.getMin()
