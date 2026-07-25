class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int cnt = 1;
        int n = nums.size();
        if(n==0) return 0 ;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                cnt++;
                ans = max(cnt, ans);
            } else if (nums[i] == nums[i - 1]) {
                continue;
            } else
                cnt = 1;
        }
        return ans;
    }
};