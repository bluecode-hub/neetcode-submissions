class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        p=[]
        result=[]
        for i in range(len(arr)):
            c=(abs(arr[i]-x),arr[i])
            p.append(c)
        p.sort()

        for i in range(k):
            result.append(p[i][1])
        result.sort()
        return result
        
        