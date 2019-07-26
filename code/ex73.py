class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """

        recorder = [[], []]

        #Record the position of 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    if i not in recorder[0]:
                        recorder[0].append(i)
                    if j not in recorder[1]:
                        recorder[1].append(j)

        #Set the row
        for i in recorder[0]:
            for j in range(len(matrix[0])):
                matrix[i][j] = 0

        #Set the column
        for j in recorder[1]:
            for i in range(len(matrix)):
                matrix[i][j] = 0

        return matrix

sol = Solution()
print(sol.setZeroes([
    [0, 1, 2, 0],
    [3, 4, 5, 2],
    [1, 3, 1, 5]
]))
