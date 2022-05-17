/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int getval(TreeNode* root,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                if(it==target) return it->val;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        }
        return root->val;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
         int value=getval(original,target);
          queue<TreeNode*> q;
          TreeNode* root=cloned;
          q.push(root);
          while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto root=q.front();
                q.pop();
                if(root->val==value) return root;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
        }
        return root;
         
    }
};