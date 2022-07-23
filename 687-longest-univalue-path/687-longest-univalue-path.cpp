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
    int maxi=0;
    int rec(TreeNode* root,int value){
        if(root==NULL) return 0;
        int left=rec(root->left,root->val);
        int right=rec(root->right,root->val);
        maxi=max(maxi,left+right);
        return root->val==value?1+max(left,right):0;
    }
    int longestUnivaluePath(TreeNode* root) {
        rec(root,10001);
        return maxi;
    }
};