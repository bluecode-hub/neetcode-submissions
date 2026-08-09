class Solution:
    def isHappy(self, n: int) -> bool:
        visited=set()
        while n not in visited:
            visited.add(n)
            n=self.sumofsquare(n)
            if n==1:
                return True
        return False
    




    def sumofsquare(self,n:int)->int:
        output=0
        while(n>0):
            digit=n%10
            digit=digit**2
            output+=digit
            n=n//10
        return output
        


        
              
        


