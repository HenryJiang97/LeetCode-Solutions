class Solution:
    def helper(self, i, j, triangle, s):
        global minimum

        if i < len(triangle):
            s += triangle[i][j]

            self.helper(i + 1, j, triangle, s)
            self.helper(i + 1, j + 1, triangle, s)
        else:
            if s < minimum:
                minimum = s


    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """

        global minimum
        minimum = 2 ** 31

        self.helper(0, 0, triangle, 0)

        return minimum


sol = Solution()
print(sol.minimumTotal([
    [2],
    [3, 4],
    [6, 5, 7],
    [4, 1, 8, 3]
]))
