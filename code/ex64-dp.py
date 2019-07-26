import copy

class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
       
       	dp = copy.deepcopy(grid)


       	for i in range(len(grid)):
       		for j in range(len(grid[0])):
       			if (i == 0) and (j == 0):
       				dp[i][j] = dp[i][j]
        		elif i == 0:
        			dp[i][j] += dp[i][j - 1]
        		elif j == 0:
        			dp[i][j] += dp[i - 1][j]
        		else:
        			dp[i][j] += min(dp[i][j - 1], dp[i - 1][j])


        return dp[-1][-1]



sol = Solution()
print(sol.minPathSum([
  [1,3,1],
  [1,5,1],
  [4,2,1]
]))