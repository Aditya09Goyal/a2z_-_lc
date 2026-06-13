class Solution {
public:
    int solve(int idx, vector<int>& dp, vector<int>& nums) {
        if (idx == 0)
            return nums[idx];
        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];
        int pick = nums[idx] + solve(idx - 2, dp, nums);
        int not_pick = solve(idx - 1, dp, nums);
        return dp[idx] = max(pick, not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, dp, nums);
    }
};
// pick means if i am at some idx , then start picking from that idx or not picking that idx and start picking from idx-1 index