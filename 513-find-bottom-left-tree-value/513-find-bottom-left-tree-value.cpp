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
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            //vector<int> ch;
            long long h=INT_MAX;
            h+=10;
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
                if(h-10==INT_MAX) h=root->val;
            }
            if(h-10!=INT_MAX) ans=h;
        }
        return ans;
    }
};