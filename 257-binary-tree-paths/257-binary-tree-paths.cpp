/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(vector<string> &ans, string &s, TreeNode *root){
        string tmp = s;
        if(s != "") s += "->"; 
        s += to_string(root->val);
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(s);
            s = tmp;
            return;
        }   
        
        if(root->left) dfs(ans, s, root->left);
        if(root->right) dfs(ans, s, root->right);
        s = tmp;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        dfs(ans, s, root);
        return ans;
    }
};