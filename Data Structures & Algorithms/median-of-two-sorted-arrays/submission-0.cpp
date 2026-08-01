class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    vector<int> nums3;

    int i = 0, j = 0;

    while(i < n && j < m){
        if(nums1[i] < nums2[j]){
            nums3.push_back(nums1[i]);
            i++;
        }else{
            nums3.push_back(nums2[j]);
            j++;
        }
    }

    while(i < n){
        nums3.push_back(nums1[i]);
        i++;
    }

    while(j < m){
        nums3.push_back(nums2[j]);
        j++;
    }

    int t = nums3.size();

    if(t % 2 == 0){
        return (nums3[t/2 - 1] + nums3[t/2]) / 2.0;
    }

    return nums3[t/2];
}
};