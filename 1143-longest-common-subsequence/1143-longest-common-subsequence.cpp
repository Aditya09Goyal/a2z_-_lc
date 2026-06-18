class Solution {
public:
    int lcs(int idx1, int idx2, vector<vector<int>>& dp, string& text1,
            string& text2) {
        if (idx1 < 0 || idx2 < 0) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        // if index matches
        if (text1[idx1] == text2[idx2]) {
            return dp[idx1][idx2] = 1 + lcs(idx1 - 1, idx2 - 1, dp, text1, text2);
        }
        else return dp[idx1][idx2] = max(lcs(idx1 - 1, idx2, dp, text1, text2),
                                    lcs(idx1, idx2 - 1, dp, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        return lcs(n - 1, m - 1, dp, text1, text2);
    }
};