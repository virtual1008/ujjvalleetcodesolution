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
    
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l=INT_MAX;
        int r=INT_MAX;
        if(root->left==NULL && root->right==NULL) return 1;
        if(root->left)
         l=height(root->left)+1;
        if(root->right)
         r=height(root->right)+1;
        return min(l,r);
    }
    
    int minDepth(TreeNode* root) {
      //if(root==NULL) return 0;
      return height(root);
        
    }
};