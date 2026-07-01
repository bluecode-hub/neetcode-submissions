class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1 && nums[0]>=0){
            return true;
        }
        int lastnumber=nums.size()-1;
        int right=nums.size()-1;
        bool flag=false;
        for(int right=nums.size()-2;right>=0;right--){
            if(right + nums[right] >= lastnumber){
                lastnumber=right;
                flag=true;
                
            }else{
                flag=false;
            }
        }
            
        if(flag==true){
            return true;
        }else{
            return false;
        }
        

        
    }
};
