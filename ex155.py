class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.r = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.r.append(x)
        

    def pop(self):
        """
        :rtype: void
        """
        self.r.pop(-1)
        

    def top(self):
        """
        :rtype: int
        """
        return self.r[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return min(self.r)


minStack = MinStack()
minStack.push(-2)
minStack.push(0)
minStack.push(-3)
minStack.getMin()
minStack.pop()
minStack.top()
minStack.getMin()
