class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        high = max(piles)
        low = 1
        res = high

        while low <= high:
            k = low + (high - low) // 2

            total_time = 0
            for p in piles:
                total_time += math.ceil(p / k)

            if total_time <= h:
                res = k
                high = k - 1
            else:
                low = k + 1

        return res