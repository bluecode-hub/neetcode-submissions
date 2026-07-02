class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backtrack(start, currsum, currlist):
            if currsum == target:
                res.append(currlist[:])
                return

            if currsum > target:
                return

            for i in range(start, len(candidates)):
                # Skip duplicates at the same recursion level
                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                backtrack(
                    i + 1,
                    currsum + candidates[i],
                    currlist + [candidates[i]]
                )

        backtrack(0, 0, [])
        return res