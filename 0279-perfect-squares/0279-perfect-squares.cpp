class Solution {
public:
    int solve(int idx, int target, vector<vector<int>>& dp,
              vector<int>& coins) {
        if (!target) return 0;
        if (idx == 0) {
            if (target % coins[idx] == 0) return target / coins[idx];
            return 1e9;
        }
        if (dp[idx][target] != -1) return dp[idx][target];
        int not_pick = solve(idx - 1, target, dp, coins);
        int pick = 1e9;
        if (coins[idx] <= target) {
            pick = 1 + solve(idx, target - coins[idx], dp, coins);
        }
        return dp[idx][target] = min(pick, not_pick);
    }
    int numSquares(int n) {
        int psq = (int)sqrt(n);
        vector<int> nums ; 
        for (int i = 1; i * i <= n; i++) nums.push_back(i * i);
        vector<vector<int>> dp(psq + 1, vector<int>(n + 1, -1));
        return solve(psq - 1, n, dp, nums);
    }
};