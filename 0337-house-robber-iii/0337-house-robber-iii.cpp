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
    map<TreeNode*,int> dp;
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int pick=root->val;
        if(root->left) pick+=(rec(root->left->left)+rec(root->left->right));
        if(root->right) pick+=(rec(root->right->left)+rec(root->right->right));
        int ntake=rec(root->left)+rec(root->right);
        return dp[root]=max(pick,ntake);
    }
    int rob(TreeNode* root) {
        return rec(root);
    }
};