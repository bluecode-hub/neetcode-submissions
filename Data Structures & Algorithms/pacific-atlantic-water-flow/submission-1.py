class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights:
            return []

        rows, cols = len(heights), len(heights[0])
        pac,alt=set(),set()
        def dfs(r,c,parent,visited):
            if r<0 or c<0 or r>=rows or c>=cols:
                return
            if (r,c) in visited:
                return
            if heights[r][c]<parent:
                return
            visited.add((r,c))
            dfs(r-1,c,heights[r][c],visited)
            dfs(r+1,c,heights[r][c],visited)
            dfs(r,c-1,heights[r][c],visited)
            dfs(r,c+1,heights[r][c],visited)

                # Pacific (top row and left column)
        for c in range(cols):
            dfs(0, c, heights[0][c], pac)

        for r in range(rows):
            dfs(r, 0, heights[r][0], pac)

        for c in range(cols):
            dfs(rows-1,c,heights[rows-1][c],alt)
        for r in range(rows):
            dfs(r,cols-1,heights[r][cols-1],alt)
        result=[]
        for r in range(rows):
            for c in range(cols):
                if (r,c) in alt and (r,c) in pac:
                    result.append([r,c])
        return result

        