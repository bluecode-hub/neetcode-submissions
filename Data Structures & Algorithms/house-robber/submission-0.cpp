class Solution {
public:
    int dfs(int i,vector<int>&dp,vector<int>&nums){
        int n=nums.size();
        if (i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=max(nums[i]+dfs(i+2,dp,nums),dfs(i+1,dp,nums));
        return dp[i];

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return dfs(0,dp,nums);


        
    }
};
