class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """

        global counter

        counter = 0
        
        #Go right
        def right(self, i, j):
            global counter

            #Counter++ when reach the destination
            if (i == n - 1) & (j == m - 1):
                counter += 1
                return

            #Return to the last position when out of range
            if (i >= n) | (j >= m):
                return

            if j < m:
                right(self, i, j + 1)
            
            if i < n:
                down(self, i + 1, j)

        #Go downward
        def down(self, i, j):
            global counter

            if (i == n - 1) & (j == m - 1):
                counter += 1
                return

            if (i >= n) | (j >= m):
                return

            if i < n:
                down(self, i + 1, j)
            
            if j < m:
                right(self, i, j + 1)

        right(self, 0, 0)

        return counter


sol = Solution()
print(sol.uniquePaths(3, 3))
