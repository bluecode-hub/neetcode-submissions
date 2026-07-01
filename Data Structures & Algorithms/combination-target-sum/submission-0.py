class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        def backtrack(start, currsum, currlist):
            if currsum == target:
                res.append(currlist)
                return

            if currsum > target:
                return

            for i in range(start, len(nums)):
                backtrack(i, currsum + nums[i], currlist + [nums[i]])

        backtrack(0, 0, [])
        return res

        