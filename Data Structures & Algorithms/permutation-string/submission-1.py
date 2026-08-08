class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        k = len(s1)

        l = [0] * 26
        l2 = [0] * 26

        left = 0

        for i in range(len(s1)):
            l[ord(s1[i]) - ord('a')] += 1

        for right in range(len(s2)):
            l2[ord(s2[right]) - ord('a')] += 1

            if right - left + 1 > k:
                l2[ord(s2[left]) - ord('a')] -= 1
                left += 1

            if right - left + 1 == k:
                if l2 == l:
                    return True

        return False