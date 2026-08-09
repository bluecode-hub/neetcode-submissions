class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
      rowss,colss=len(matrix),len(matrix[0])
      rows,cols=[False]*rowss,[False]*colss
      for r in range(rowss):
        for c in range(colss):
            if matrix[r][c]==0:
                rows[r]=True
                cols[c]=True
      for r in range(rowss):
        for c in range(colss):
            if rows[r] or cols[c]:
                matrix[r][c]=0

        
        