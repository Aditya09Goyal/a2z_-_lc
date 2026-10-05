class Solution {
public:
    int cnt = 0 ; 
    int solve(int &ans , TreeNode* root)
    {
        if(root==NULL) return 0 ; 
        int leftcnt = 0 , rightcnt = 0 ; 
        int l = solve(leftcnt,root->left);
        int r = solve(rightcnt,root->right);

        ans = leftcnt + rightcnt + 1 ; 
        int sum = l + r + root->val; 

        if(sum/ans == root->val) cnt++ ;
        return sum;

    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0 ; 
        solve(ans,root); 
        return cnt; 
    }
};