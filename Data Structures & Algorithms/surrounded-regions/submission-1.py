class Solution:
    def solve(self, board: List[List[str]]) -> None:
        visited=set()
        row,col=len(board),len(board[0])
        def dfs(r,c):
            if r<0 or c<0 or r==row or c==col:
                return
            if board[r][c] != "O":
                return
            if board[r][c]=="O":
                board[r][c]="#"
            if (r,c) in visited:
                return

            
            visited.add((r,c))
            dfs(r-1,c)
            dfs(r+1,c)
            dfs(r,c-1)
            dfs(r,c+1)

                
            
        for i in range (row):
            for j in range (col):
                if (i==0 or j==0 or i==row-1 or j==col-1) and board[i][j]=="O":
                    dfs(i,j)
        for i in range(row):
            for j in range(col):
                if board[i][j]=="O":
                    board[i][j]="X"
                if board[i][j]=="#":
                    board[i][j]="O"
                
        
        
        