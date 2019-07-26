class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """

        r = ''

        while n > 26:
            residual = n % 26
            n = n // 26

            if residual != 0:
                r = chr(residual + 64) + r
            else:
                r = 'Z' + r
                n -= 1

        r = chr(n + 64) + r

        return r    


sol = Solution()
print(sol.convertToTitle(52))