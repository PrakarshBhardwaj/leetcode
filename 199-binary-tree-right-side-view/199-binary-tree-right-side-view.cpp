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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        TreeNode *tmp;
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i = 0; i < n - 1; i++){
                tmp = q.front();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                q.pop();
            }
            
            tmp = q.front();
            ans.push_back(tmp->val);
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            q.pop();
        }
        
        return ans;
    }
};