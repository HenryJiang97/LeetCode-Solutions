class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """

        result = []

        #Consider unique situation
        if (m == 0) | (n == 0):
            return 0
        
        if (m == 1) & (n == 1):
            return 1

        for i in range(n):
            result.append([])
            for j in range(m):
                result[i].append(-1)

        return self.dp(m - 1, n - 1, result)

    def dp(self, m, n, result):
        if (m < 0) | (n < 0):
            return 0

        #The init route should be 1, found the starting point
        if (m == 0) and (n == 0):
            return 1

        #Go back
        if result[n][m] != -1:
            return result[n][m]
        else:
            #Num of route = upper + left
            result[n][m] = self.dp(m - 1, n, result) + self.dp(m, n - 1, result)
            return result[n][m]


sol = Solution()
print(sol.uniquePaths(3, 2))
