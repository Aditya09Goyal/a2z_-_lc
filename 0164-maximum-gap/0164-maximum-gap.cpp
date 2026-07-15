class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size(); 
        if(n<2) return 0 ;
        sort(begin(nums),end(nums)) ; 
        int maxi = 0 ; 
        for(int i=1;i<n;i++)
        {
            maxi = max(maxi,nums[i]-nums[i-1]);
        }
        return maxi;
    }
};