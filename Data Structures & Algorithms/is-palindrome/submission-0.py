class Solution:
    def isPalindrome(self, s: str) -> bool:
        store=''
        for i in range(len(s)):
            if s[i].isalnum():
              store += s[i].lower()
        return store==store[::-1]
        