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
    TreeNode* rec(TreeNode* root,int depth,int val){
        if(depth<=0 || root==NULL) return NULL;
        if(depth==2){
            TreeNode* left=root->left;
            TreeNode* right=root->right;
            TreeNode* a1=new TreeNode(val);
            TreeNode* a2=new TreeNode(val);
            root->left=a1;
            root->right=a2;
            a1->left=left;
            a2->right=right;
            return root;
        }
        rec(root->left,depth-1,val);
        rec(root->right,depth-1,val);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth>1) rec(root,depth,val);
        else{
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        return root;
    }
};