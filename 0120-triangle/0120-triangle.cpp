class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // base case
        for (int j = n - 1; j >= 0; j--) {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        // tabulation
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int bottom = triangle[i][j] + dp[i + 1][j];
                int right_diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(bottom, right_diag);
            }
        }
        return dp[0][0];
    }
};