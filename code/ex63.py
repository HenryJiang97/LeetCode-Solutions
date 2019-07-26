class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        result = []

        #Consider unique situation
        if (len(obstacleGrid) == 0) | (len(obstacleGrid[0]) == 0):
            return 0

        #If the starting point is an obstacle, no valid route
        if obstacleGrid[0][0] == 1:
            return 0

        #If there is only one point, number of routes should be 1
        if (len(obstacleGrid) == 1) & (len(obstacleGrid[0]) == 1):
            return 1

        #Create a route map
        for i in range(len(obstacleGrid)):
            result.append([])
            for j in range(len(obstacleGrid[0])):
                if obstacleGrid[i][j] != 1:
                    result[i].append(-1)
                else:
                    result[i].append(0)

        return self.dp(len(obstacleGrid[0]) - 1, len(obstacleGrid) - 1, result)

    def dp(self, m, n, result):
        if (m < 0) | (n < 0):
            return 0

        #The init route should be 1, found the starting point
        if (m == 0) and (n == 0):
            return 1

        #Go back
        if (result[n][m] != -1) & (result[n][m] != 0):
            return result[n][m]
        else:
            #Num of route = upper + left
            if (result[n][m] != 0):
                result[n][m] = self.dp(m - 1, n, result) + self.dp(m, n - 1, result)
            else:
                #When meet the obstacle, return 0
                result[n][m] = 0

            return result[n][m]


sol = Solution()
print(sol.uniquePathsWithObstacles([[1, 0],[0, 0], [1,1]]))
