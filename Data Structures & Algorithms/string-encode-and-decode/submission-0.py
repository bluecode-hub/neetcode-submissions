class Solution:

    def encode(self, strs: List[str]) -> str:
        finalstr=""
        for i in strs:
            finalstr+=i
            finalstr+='(*^)'
        return finalstr

    def decode(self, s: str) -> List[str]:
        
        l=s.split('(*^)')[:-1]
        return l
