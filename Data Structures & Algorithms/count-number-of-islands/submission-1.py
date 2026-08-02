from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row=len(grid)
        col=len(grid[0])
        visited=set()
        def dfs(r,c):
            if r<0 or c<0 or r>=row or c>=col:
                return
            if grid[r][c]=='0':
                return
            if (r,c) in visited:
                return 
            visited.add((r,c))
            dfs(r-1,c)
            dfs(r+1,c)
            dfs(r,c+1)
            dfs(r,c-1)
        count=0
        for i in range(row):
            for j in range(col):
                if grid[i][j]=='1' and (i,j) not in visited:
                    dfs(i,j)
                    count=count+1
        return count
        
            
        