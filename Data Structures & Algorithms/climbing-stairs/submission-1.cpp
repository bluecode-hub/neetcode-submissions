class Solution {
public:
    int fibnoci(int n, vector<int>& dp) {
        if (n == 0 || n == 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = fibnoci(n - 1, dp) + fibnoci(n - 2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 2, -1);
        return fibnoci(n + 1, dp);
    }
};