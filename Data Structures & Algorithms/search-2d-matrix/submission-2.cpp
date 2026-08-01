class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
       int m=matrix[0].size();
       int whatrow=-1;
       for(int i=0;i<n;i++){
         if(matrix[i][m-1]<target){
            whatrow=i+1;
         }else if (matrix[i][m-1]>=target){
            whatrow=i;
            break;
            }
       }
       if (whatrow == n)
          return false;
       int low=0;
       int high=m-1;
       bool flag=false;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(target<matrix[whatrow][mid]){
            high=mid-1;
        }else if(target>matrix[whatrow][mid]){
            low=mid+1;
        }
        else{
            flag=true;
            return flag;
        }
    }
    return flag;
        
    }
};
