class Solution:
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """

        mark = 0
        for i in range(1, len(board) - 1):
            for j in range(1, len(board[0]) - 1):

                if board[i][j] == 'O':
                    if i == 1:
                        if board[0][j] == 'O':
                            mark = 1

                    if i == len(board) - 2:
                        if board[len(board) - 1][j] == 'O':
                            mark = 1

                    if j == 1:
                        if board[i][0] == 'O':
                            mark = 1

                    if j == len(board[0]) - 2:
                        if board[i][len(board[0]) - 1] == 'O':
                            mark = 1

                    if mark == 0:
                        board[i][j] = 'X'

        return board

sol = Solution()
print(sol.solve([["O", "X", "X", "O", "X"], ["X", "O", "O", "X", "O"], [
      "X", "O", "X", "O", "X"], ["O", "X", "O", "O", "O"], ["X", "X", "O", "X", "O"]]))
