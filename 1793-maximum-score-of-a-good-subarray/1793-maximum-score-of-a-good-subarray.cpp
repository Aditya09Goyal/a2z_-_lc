class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l=k,r=k;
        int score = nums[k] ;
        int mini = nums[k]; 
        int n=nums.size(); 
        while(l>0 or r<n-1) {
             if(l==0) r++ ;
             else if(r==nums.size()-1) l--;
             // length ↑  mini ↓ =>  score ↑ 
             else if(nums[l-1]>nums[r+1]) l--;
             else r++; 
             mini = min({mini,nums[l],nums[r]}) ;
             score= max(score,mini*(r-l+1)) ;
        }
        return score ;
    }
};