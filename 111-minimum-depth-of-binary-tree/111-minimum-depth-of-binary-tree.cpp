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
    int mi=INT_MAX;
    void findans(TreeNode* root,int count)
    {
        if(!root)
            return ;
        if(root->left==nullptr && root->right==nullptr)
        {
            mi=min(mi,count+1);
            return ;
        }
        count++;
        findans(root->left,count);
        findans(root->right,count);
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        findans(root,0);
        return mi;
    }
};