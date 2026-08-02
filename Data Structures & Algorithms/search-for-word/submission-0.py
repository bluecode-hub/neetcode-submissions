class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        row=len(board)
        col=len(board[0])
        visited=set()
        def dfs(r,c,idx):
            if(r<0 or c<0 or r==row or c==col or board[r][c]!=word[idx] or (r,c) in visited):
                return False
            if idx==len(word)-1:
                return True
            visited.add((r,c))
            res=(
                dfs(r-1,c,idx+1) or
                dfs(r+1,c,idx+1) or
                dfs(r,c-1,idx+1) or
                dfs(r,c+1,idx+1)
            )
            visited.remove((r,c))
            return res
         
        for r in range(row):
            for c in range(col):
                if dfs(r,c,0):
                    return True
        return False
        


        