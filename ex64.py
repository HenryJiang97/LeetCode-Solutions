class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        global s
        global sumList

        s = 0
        sumList = []

        m = len(grid[0])
        n = len(grid)

        #Go right
        def right(self, i, j):
            global s
            global sumList

            #Counter++ when reach the destination
            if (i == n - 1) & (j == m - 1):
                s += grid[i][j]
                print(s)
                sumList.append(s)
                s -= grid[i][j]
                return

            #Return to the last position when out of range
            if (i >= n) | (j >= m):
                return

            s += grid[i][j]

            if j < m:
                right(self, i, j + 1)

            if i < n:
                down(self, i + 1, j)

        #Go downward
        def down(self, i, j):
            global s
            global sumList

            if (i == n - 1) & (j == m - 1):
                s += grid[i][j]
                print(s)
                sumList.append(s)
                s -= grid[i][j]
                return

            if (i >= n) | (j >= m):
                return

            s += grid[i][j]

            if i < n:
                down(self, i + 1, j)

            if j < m:
                right(self, i, j + 1)

        right(self, 0, 0)

        return sumList

sol = Solution()
print(sol.minPathSum([
  [1,3,1],
  [1,5,1],
  [4,2,1]
]))
