import math

class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """

        num = [(i + 1) for i in range(n)]

        r = ''

        k -= 1

        while n > 0:
            n -= 1

            index = k // (math.factorial(n))
            r += str(num[index])
            k = k % (math.factorial(n))

            #Remove index item
            num.remove(num[index])

        return r

sol = Solution()
print(sol.getPermutation(3, 3))
