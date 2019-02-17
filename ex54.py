class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """

        #Consider two specific conditions
        if len(matrix) == 0:
            return matrix
        elif len(matrix) == 1:
            return matrix[0]


        r = []

        #Init visited list
        visited = []
        for i in range(len(matrix)):
            l = []
            
            for j in range(len(matrix[0])):
                l.append(0)

            visited.append(l)

        
        #Define paths to 4 different directions
        def loop_x_right(self, i, j, matrix, visited):
            #If all visited, return
            if visited[i][j] == 1:
                return

            while j < len(matrix[0]):
                #If the path hit the wall, head to the next direction
                if visited[i][j] == 1:
                    loop_y_down(self, i + 1, j - 1, matrix, visited)
                else:
                    #Add path to list r
                    r.append(matrix[i][j])
                    visited[i][j] = 1

                j += 1

            loop_y_down(self, i + 1, j - 1, matrix, visited)


        def loop_y_down(self, i, j, matrix, visited):
            if visited[i][j] == 1:
                return

            while i < len(matrix):
                if visited[i][j] == 1:
                    loop_x_left(self, i - 1, j - 1, matrix, visited)
                else:
                    r.append(matrix[i][j])
                    visited[i][j] = 1

                i += 1

            loop_x_left(self, i - 1, j - 1, matrix, visited)


        def loop_x_left(self, i, j, matrix, visited):
            if visited[i][j] == 1:
                return

            while j >= 0:
                if visited[i][j] == 1:
                    loop_y_up(self, i - 1, j + 1, matrix, visited)
                else:
                    r.append(matrix[i][j])
                    visited[i][j] = 1

                j -= 1

            loop_y_up(self, i - 1, j + 1, matrix, visited)


        def loop_y_up(self, i, j, matrix, visited):
            if visited[i][j] == 1:
                return

            while i >= 0:
                if visited[i][j] == 1:
                    loop_x_right(self, i + 1, j + 1, matrix, visited)
                else:
                    r.append(matrix[i][j])
                    visited[i][j] = 1

                i -= 1

            loop_x_right(self, i, j + 1, matrix, visited)


        #The first direction
        loop_x_right(self, 0, 0, matrix, visited)

        return r


sol = Solution()
print(sol.spiralOrder([
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]))