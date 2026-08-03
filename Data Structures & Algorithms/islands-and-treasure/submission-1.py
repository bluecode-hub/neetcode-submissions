class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        d=deque()
        visited=set()
        row=len(grid)
        col=len(grid[0])
        for i in range(row):
            for j in range(col):
                if grid[i][j]==0:
                    d.append((i,j))
                    visited.add((i,j))
        dirx = [1, -1, 0, 0]
        diry = [0, 0, -1, 1]

        while d:
            sz=len(d)
            for _ in range(sz):
                curr=d.popleft()
                
                x,y=curr
                for i in range(4):
                   nx=x+dirx[i]
                   ny=y+diry[i]
                   if nx<0 or ny<0 or nx>=row or ny>=col:
                        continue
                   if (nx,ny) not in visited and grid[nx][ny]==2147483647:
                        grid[nx][ny]=grid[x][y]+1
                        visited.add((nx,ny))
                        d.append((nx,ny))
                        
                   

                    

            
            
            
        

        