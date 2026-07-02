class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        def backtrack(start, currList):
            # Found a valid combination
            if len(currList) == k:
                res.append(currList[:])
                return

            # Try all numbers from 'start' onwards
            for i in range(start, n + 1):
                backtrack(i + 1, currList + [i])

        backtrack(1, [])
        return res