class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        row = len(matrix)
        col = len(matrix[0])

        dp = [[0] * col for _ in range(row)]

        def path(r, c):

            if dp[r][c] != 0:
                return dp[r][c]

            ans = 1

            if r > 0 and matrix[r-1][c] > matrix[r][c]:
                ans = max(ans, 1 + path(r-1, c))

            if r < row-1 and matrix[r+1][c] > matrix[r][c]:
                ans = max(ans, 1 + path(r+1, c))

            if c > 0 and matrix[r][c-1] > matrix[r][c]:
                ans = max(ans, 1 + path(r, c-1))

            if c < col-1 and matrix[r][c+1] > matrix[r][c]:
                ans = max(ans, 1 + path(r, c+1))

            dp[r][c] = ans
            return dp[r][c]

        res = 0

        for r in range(row):
            for c in range(col):
                res = max(res, path(r, c))

        return res