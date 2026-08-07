class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d={}
        left=0
        ans=0
        for right in range(0,len(s)):
            if s[right] not in d:
                d[s[right]]=0
            d[s[right]]+=1
            while(d[s[right]]>1):
                d[s[left]]-=1
                left=left+1
            ans=max(ans,right-left+1)
        return ans
            
        
        