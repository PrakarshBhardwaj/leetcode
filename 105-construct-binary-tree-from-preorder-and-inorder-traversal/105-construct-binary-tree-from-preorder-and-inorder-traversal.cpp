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
    map<int, int> mp;
    
    TreeNode *go(vector<int> &pre, vector<int> &in, int strt, int end){
        if(strt > end) return NULL;
        
        TreeNode *root = NULL;
        int i;
        
        for(i = 0; i < pre.size(); i++){
            if(mp[pre[i]] >= strt && mp[pre[i]] <= end){
                root = new TreeNode(pre[i]);
                break;
            }
        }
        
        root->left = go(pre, in, strt, mp[root->val] - 1);
        root->right = go(pre, in, mp[root->val] + 1, end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        
        return go(preorder, inorder, 0, n - 1);
    }
};