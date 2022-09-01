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
    int dfs(TreeNode* root,int maxi){
        if(root==NULL) return 0;
        if(root->val>=maxi){
            maxi=max(maxi,root->val);
            return 1+dfs(root->left,maxi)+dfs(root->right,maxi);
        }
        return dfs(root->left,maxi)+dfs(root->right,maxi);
        
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};