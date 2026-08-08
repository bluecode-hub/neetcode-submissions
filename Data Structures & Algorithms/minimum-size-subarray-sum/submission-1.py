class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        k=len(nums)
        left=0
        minlength=10000
        sum=0
        for right in range(k):
            sum=sum+nums[right]
            if (sum>=target):
                while(left<=right and sum>=target):
                     length=(right-left+1)
                     minlength=min(length,minlength)
                     sum=sum-nums[left]
                     left+=1
        if(minlength==10000):
            return 0
        
        return minlength

        