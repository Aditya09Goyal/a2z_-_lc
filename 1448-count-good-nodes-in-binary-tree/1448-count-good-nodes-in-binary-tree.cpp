class Solution {
public:
    int solve(TreeNode* root, int maxi) {
        if (!root) return 0;
        int ans = 0;
        if (root->val >= maxi) ans++;
        maxi = max(maxi, root->val);
        ans += solve(root->left, maxi);
        ans += solve(root->right, maxi);
        return ans;
    }
    int goodNodes(TreeNode* root) {
         return solve(root, -1e5);    
    }
};