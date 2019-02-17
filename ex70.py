class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """

        #Fibnacci array

        temp_1 = 1
        temp_2 = 1

        if n == 1:
            return 1

        for i in range(n - 1):
            temp = temp_1 + temp_2
            temp_2 = temp_1
            temp_1 = temp

        return temp

sol = Solution()
print(sol.climbStairs(2))
