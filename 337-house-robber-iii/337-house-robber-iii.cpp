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
    int rec(TreeNode * Node){
        if(Node==NULL) return 0;
        if(dp[Node]!=0) return dp[Node];
        if(Node->left==NULL && Node->right==NULL) return Node->val;
        int pick=Node->val;
        if(Node->left) pick+=rec(Node->left->left)+rec(Node->left->right);
        if(Node->right)pick+=rec(Node->right->left)+rec(Node->right->right);
        int notpick=rec(Node->left)+rec(Node->right);
        return dp[Node]=max(pick,notpick);
    }
    int rob(TreeNode* root) {
        return rec(root);
    }
};