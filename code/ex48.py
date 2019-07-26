import copy

class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        
        backup = copy.deepcopy(matrix)

        for j in range(len(backup)):
            for i in range(len(backup)):
                matrix[j][i] = backup[len(backup) - 1 - i][j]


sol = Solution()
print(sol.rotate([[1,2,3],[4,5,6],[7,8,9]]))