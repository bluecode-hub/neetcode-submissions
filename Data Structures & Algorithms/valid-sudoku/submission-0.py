class Solution:

    def check(board, row, col, number):

        for i in range(9):
            if board[row][i] == number and i != col:
                return False

        for i in range(9):
            if board[i][col] == number and i != row:
                return False

        startRow = (row // 3) * 3
        startCol = (col // 3) * 3

        for i in range(startRow, startRow + 3):
            for j in range(startCol, startCol + 3):
                if board[i][j] == number and not (i == row and j == col):
                    return False

        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:

        for i in range(9):
            for j in range(9):

                if board[i][j] == '.':
                    continue

                if not Solution.check(board, i, j, board[i][j]):
                    return False

        return True