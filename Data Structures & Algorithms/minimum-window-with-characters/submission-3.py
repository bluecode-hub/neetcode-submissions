class Solution:
    def minWindow(self, s: str, t: str) -> str:
        hash1 = {}
        hash2 = {}
        left = 0
        minlength = 1000000000
        st = ""

        for i in range(len(t)):
            hash2[t[i]] = 1 + hash2.get(t[i], 0)

        have = 0
        need = len(hash2)

        for right in range(len(s)):
            hash1[s[right]] = 1 + hash1.get(s[right], 0)

            # Character has now reached its required frequency
            if s[right] in hash2 and hash1[s[right]] == hash2[s[right]]:
                have += 1

            while have == need:

                prevlength = minlength
                minlength = min(minlength, right - left + 1)

                if minlength != prevlength:
                    st = s[left:right + 1]

                # Remove left character
                hash1[s[left]] -= 1

                # We no longer satisfy this character's requirement
                if s[left] in hash2 and hash1[s[left]] < hash2[s[left]]:
                    have -= 1

                left += 1

        return st