class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        int count=0;
        for(auto &it:mp){
            if(it.second>1){
                count++;
            }
        }
        if(count>0){
            return true;
        }
        return false;
        
    }
};