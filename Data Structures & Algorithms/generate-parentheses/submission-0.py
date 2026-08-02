class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        def backtrack(n,currsum,e,o):
            if len(currsum)==2*n:
                res.append(currsum)
                return
            if(e<n):
                backtrack(n,currsum+'(',e+1,o)
            if(o<e):
                backtrack(n,currsum+')',e,o+1)
        backtrack(n,"",0,0)
        return res
            
        