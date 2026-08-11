class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row=len(matrix)
        col=len(matrix[0])
        search_row=0
        for i in range(row):
            if matrix[i][col-1]>=target:
                search_row=i
                break
        low=0
        high=col-1
        while(low<=high):
            mid=low+(high-low)//2
            if(matrix[search_row][mid]<target):
                low=mid+1
            elif(matrix[search_row][mid]>target):
                high=mid-1
            else:
                return True
        return False
              



        