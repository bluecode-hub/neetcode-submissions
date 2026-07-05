class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]):
        visited = set()
        row, col = len(grid), len(grid[0])
        maxarea = 0

        def dfs(r, c):
            nonlocal area, maxarea

            if r < 0 or c < 0 or r >= row or c >= col:
                return
            if (r, c) in visited:
                return
            if grid[r][c] == 0:
                return

            area += 1
            maxarea = max(maxarea, area)
            visited.add((r, c))

            dfs(r - 1, c)
            dfs(r + 1, c)
            dfs(r, c - 1)
            dfs(r, c + 1)

        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1 and (r, c) not in visited:
                    area = 0
                    dfs(r, c)

        return maxarea
        