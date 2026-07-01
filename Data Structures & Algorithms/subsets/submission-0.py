class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(start, currlist):
            res.append(currlist[:])

            for i in range(start, len(nums)):
                backtrack(i + 1, currlist + [nums[i]])

        backtrack(0, [])
        return res