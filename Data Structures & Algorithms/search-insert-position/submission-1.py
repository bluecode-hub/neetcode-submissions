class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low=0
        high=len(nums)-1
        res=len(nums)
        while(low<=high):
            mid=low+int((high-low)/2)
            if nums[mid]==target:
                return mid
            if nums[mid]>target:
                res=mid
                high=mid-1
            else:
                low=mid+1
        return res
        