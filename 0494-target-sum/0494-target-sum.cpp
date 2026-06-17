class Solution {
public:
    int n;
    int solve(int idx, int sum, int target, vector<int>& arr) {
        if (idx == n)
            return sum == target;
        int plus = solve(idx + 1, sum + arr[idx], target, arr);
        int minus = solve(idx + 1, sum - arr[idx], target, arr);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        n = arr.size();
        return solve(0, 0, target, arr);
    }
};