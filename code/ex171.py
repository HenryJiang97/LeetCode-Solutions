class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """

        r = 0
        for i in range(len(s)):
            r += (ord(s[i]) - 64) * (26 ** (len(s) - i - 1))

        return r

sol = Solution()
print(sol.titleToNumber('AB'))
