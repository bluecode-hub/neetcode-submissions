class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res=[]
        path=[]
        def isPalindrome(sub):
            return sub==sub[::-1]
        def dfs(start):
            if start==len(s):
                res.append(path.copy())
                return
            for end in range(start,len(s)):
                part=s[start:end+1]
                if isPalindrome(part):
                    path.append(part)
                    dfs(end+1)
                    path.pop()
        dfs(0)
        return res

