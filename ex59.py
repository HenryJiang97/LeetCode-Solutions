class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """

        #When n == 1, return [[1]]
        if n == 1:
            return[[1]]

        #Create a n*n matrix with all value = 0
        r = []
        for i in range(n):
            r.append([])
            for j in range(n):
                r[i].append(0)

        #Define paths to 4 different directions
        def loop_x_right(self, i, j, r, counter):
            #If all visited, return
            if r[i][j] != 0:
                return

            while j < len(r[0]):
                #If the path hit the wall, head to the next direction
                if r[i][j] != 0:
                    loop_y_down(self, i + 1, j - 1, r, counter)
                else:
                    #Add path to list r
                    r[i][j] = counter
                    counter += 1

                j += 1

            loop_y_down(self, i + 1, j - 1, r, counter)

        def loop_y_down(self, i, j, r, counter):
            if r[i][j] != 0:
                return

            while i < len(r):
                if r[i][j] != 0:
                    loop_x_left(self, i - 1, j - 1, r, counter)
                else:
                    r[i][j] = counter
                    counter += 1

                i += 1

            loop_x_left(self, i - 1, j - 1, r, counter)

        def loop_x_left(self, i, j, r, counter):
            if r[i][j] != 0:
                return

            while j >= 0:
                if r[i][j] != 0:
                    loop_y_up(self, i - 1, j + 1, r, counter)
                else:
                    r[i][j] = counter
                    counter += 1

                j -= 1

            loop_y_up(self, i - 1, j + 1, r, counter)

        def loop_y_up(self, i, j, r, counter):
            if r[i][j] != 0:
                return

            while i >= 0:
                if r[i][j] != 0:
                    loop_x_right(self, i + 1, j + 1, r, counter)
                else:
                    r[i][j] = counter
                    counter += 1

                i -= 1

            loop_x_right(self, i, j + 1, r, counter)

        loop_x_right(self, 0, 0, r, 1)

        return r

sol = Solution()
print(sol.generateMatrix(5))
