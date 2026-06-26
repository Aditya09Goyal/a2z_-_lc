class Codec {
public:
    void Preorder(TreeNode* root, string& s) {
        if (root == NULL) {
             s += "N," ; 
            return;
        }
        s += to_string(root->val) + ",";
        Preorder(root->left, s);
        Preorder(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return {};
        string preorder ; 
        Preorder(root, preorder);
        preorder.pop_back() ; 
        return preorder ; 
    }
    TreeNode* solve(stringstream& ss) {
        string val ; 
        getline(ss,val,','); 
        if(val=="N") return NULL ; 
        TreeNode* root = new TreeNode(stoi(val)) ; 
        root->left = solve(ss) ;
        root->right = solve(ss) ; 
        return root ;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data) ;
        return solve(ss) ;      
    }    
};