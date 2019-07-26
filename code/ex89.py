# A easy solution, no bit operation:
# for example you have the answer for n = 2 as (00, 01, 11, 10), how you can get the answer for n = 3?
# (1) you need all the answer in n = 2, copy them(000, 001, 011, 010)
# (2) add pow(2, 2) = 4 to all the answer in n = 2 as in (1) and add them to n = 3, BUT! start from the last one, that is (110, 111, 101, 100)!!!

import copy

class Solution:
    #Input b is string type
    def binaryToDecimal(self, b):
        r = 0
        
        for i in range(len(b)):
            if b[i] == '1':
                r += 2**(len(b) - int(i) - 1)

        return r

    def adding(self, a):
        backup = copy.deepcopy(a)

        #Add 0 to the front of each item in a, add 1 to the front of each item in backup
        for i in range(len(a)):
            a[i] = '0' + a[i]
            backup[i] = '1' + backup[i]

        #Add backup reversely to the end of a
        for i in range(len(backup) - 1, -1, -1):
            a.append(backup[i])

        return a


    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """

        a = ['0', '1']
        r = []

        if n == 0:
            return [0]

        if n == 1:
            return [0, 1]

        #Generate new binary list
        for counter in range(n - 1):
            a = self.adding(a)

        #Binary to decimal
        for i in range(len(a)):
            r.append(self.binaryToDecimal(a[i]))

        return r



sol = Solution()
print(sol.grayCode(2))
