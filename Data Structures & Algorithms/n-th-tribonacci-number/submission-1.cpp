class Solution {
public:
    int fibonacci(int n,vector<int>&dp){
         if(n==0||n==1){
            return n;
        }
        if(n==2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp)+fibonacci(n-3,dp);
        return dp[n];

    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return fibonacci(n,dp);
       

        
    }
};