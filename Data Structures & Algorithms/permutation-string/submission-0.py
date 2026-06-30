class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        k = len(s1)

        l = [0] * 26
        l2 = [0] * 26

        left = 0

        for i in range(k):
            l[ord(s1[i]) - ord('a')] += 1

        for r in range(len(s2)):
            l2[ord(s2[r]) - ord('a')] += 1

            if (r - left + 1) > k:
                l2[ord(s2[left]) - ord('a')] -= 1
                left += 1

            if (r - left + 1) == k:
                if l == l2:
                    return True

        return False   

        