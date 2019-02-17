class Solution:
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """

        if n < 1:
            return 0

        num_zeros = 0
        pow_of_5 = 5

        while pow_of_5 <= n:
            num_zeros += n // pow_of_5
            pow_of_5 *= 5

        return num_zeros

sol = Solution()
print(sol.trailingZeroes(30))
