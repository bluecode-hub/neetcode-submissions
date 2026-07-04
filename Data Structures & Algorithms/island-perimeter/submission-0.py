class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        visited = set()
        rows, cols = len(grid), len(grid[0])
        count = 0

        def perimeter(r, c):
            nonlocal count

            if r < 0 or c < 0 or r >= rows or c >= cols:
                count += 1
                return

            if grid[r][c] == 0:
                count += 1
                return

            if (r, c) in visited:
                return

            visited.add((r, c))

            perimeter(r - 1, c)
            perimeter(r + 1, c)
            perimeter(r, c - 1)
            perimeter(r, c + 1)

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    perimeter(r, c)
                    return count

        return 0
        