class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        #Decide row and column
        existed_row = []
        existed_column = []

        for i in range(0, 9):
            for j in range(0, 9):
                if (board[i][j] not in existed_row) & (board[j][i] not in existed_column):
                    if board[i][j] != '.':
                        existed_row.append(board[i][j])
                    if board[j][i] != '.':
                        existed_column.append(board[j][i])

                else:
                    return False
                
            existed_row.clear()
            existed_column.clear()

        #Decide boxes
        x = 0
        y = 0
        existed = []

        for controller_i in range(0,3):
            for controller_j in range(0,3):
                for i in range(x, x + 3):
                    for j in range(y, y + 3):
                        if board[i][j] not in existed:
                            if board[i][j] != '.':
                                existed.append(board[i][j])
                        else:
                            return False

                existed.clear()
                x += 3
    
            x = 0
            y += 3

        return True

sol = Solution()
print(sol.isValidSudoku([
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]))