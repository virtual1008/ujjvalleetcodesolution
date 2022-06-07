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
    int rec(TreeNode* root ,map<TreeNode*,int>& dp){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        if(dp[root]!=0) return dp[root];
        int pick=root->val;
        if(root->left) pick+=rec(root->left->left,dp)+rec(root->left->right,dp);
        if(root->right) pick+=rec(root->right->left,dp)+rec(root->right->right,dp);
        int notpick=rec(root->left,dp)+rec(root->right,dp);
        return dp[root]=max(pick,notpick);
    }
    int rob(TreeNode* root) {
        map<TreeNode*,int> dp;
        int c=rec(root,dp);
        return c;
    }
};