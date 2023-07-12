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
    map<TreeNode*,TreeNode*> parent;
    void rec(TreeNode* root){
        if(root==NULL)return;
        if(root->left){
            parent[root->left]=root;
            rec(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            rec(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(target);
        rec(root);
        map<TreeNode*,bool> vis;
        vis[target]=true;
        while(!q.empty()){
            int n=q.size();
            if(k==0) break;
            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
                if(parent[temp] && !vis[parent[temp]]){
                    q.push(parent[temp]);
                    vis[parent[temp]]=true;
                }
            }
            k--;
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans.push_back(it->val);
        }
        return ans;
    }
};