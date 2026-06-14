class Solution {
public:
    int m, n;
    int solve(int i, int j1, int j2, vector<vector<vector<int>>>& dp, vector<vector<int>>& arr) {
        if (j1 < 0 or j2 < 0 or j1 >= n or j2 >= n) return 0;
        if (i == m - 1) {
            if (j1 == j2)
                return arr[i][j1];
            else
                return arr[i][j1] + arr[i][j2];
        }
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int ans = 0;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                if (j1 == j2) {
                    ans = max(ans, arr[i][j1] +
                                       solve(i + 1, j1 + d1, j2 + d2, dp, arr));
                } else {
                    ans = max(ans, arr[i][j1] + arr[i][j2] +
                                       solve(i + 1, j1 + d1, j2 + d2, dp, arr));
                }
            }
        }
        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& arr) {
        m = arr.size();
        n = arr[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, n - 1, dp, arr);
    }
};