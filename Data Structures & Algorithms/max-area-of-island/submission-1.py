class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]):
        row=len(grid)
        col=len(grid[0])
        visited=set()
        maxarea=0;
        def dfs(r,c):
            nonlocal area,maxarea
            if r<0 or c<0 or r>=row or c>=col:
                return 
            if (r,c) in visited:
                return 
            if grid[r][c]==0:
                return
            area=area+1;
            maxarea=max(area,maxarea)
            visited.add((r,c))
            dfs(r-1,c)
            dfs(r+1,c)
            dfs(r,c-1)
            dfs(r,c+1)
        for i in range(row):
            for j in range(col):
                if grid[i][j]==1 and (i,j) not in visited:
                    area=0
                    dfs(i,j)
        return maxarea



        