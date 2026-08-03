class Solution:
    def solve(self, grid: List[List[str]]) -> None:
        visited=set()
        row=len(grid)
        col=len(grid[0])
        def dfs(r,c):
            if r<0 or c<0 or r>=row or c>=col:
                return
            if (r,c) in visited:
                return
            if grid[r][c]=='X':
                return
            if grid[r][c]=='O':
                grid[r][c]='#'
            visited.add((r,c))
            dfs(r-1,c)
            dfs(r+1,c)
            dfs(r,c-1)
            dfs(r,c+1)
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 'O' and (
    i == 0 or j == 0 or i == row-1 or j == col-1
):
                     dfs(i,j)
        for i in range(row):
            for j in range(col):
                if grid[i][j]=='O':
                    grid[i][j]='X'
                if grid[i][j]=='#':
                    grid[i][j]='O'

        
                
        
        
        