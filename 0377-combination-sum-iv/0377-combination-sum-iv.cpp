class Solution {
public:
    int combinationSum4(vector<int>& arr, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1; 
        for (int i = 1; i <= target; i++) {
            for (int num : arr) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
