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
    map<TreeNode*,TreeNode*> mp;
    map<TreeNode* ,bool> vis;
    TreeNode* parentmap(TreeNode* root,int start){
        TreeNode* Node=root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                if(temp->val==start) Node=temp;
                q.pop();
                if(temp->left){
                    mp[temp->left]=temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    mp[temp->right]=temp;
                    q.push(temp->right);
                }
            }
        }
        return Node;
    }
    int distance(TreeNode* start){
        int k=0;
        queue<TreeNode*> q;
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int n=q.size();
            bool flag=false;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && vis[temp->left]==false){
                    vis[temp->left]=true;
                    q.push(temp->left);
                    flag=true;
                }
                if(temp->right && vis[temp->right]==false){
                    vis[temp->right]=true;
                    q.push(temp->right);
                    flag=true;
                }
                if(mp[temp] && vis[mp[temp]]==false){
                    vis[mp[temp]]=true;
                    q.push(mp[temp]);
                    flag=true;
                }
            }
            if(flag) k++;
        }
        return k;
        
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* node=parentmap(root,start);
        
        return distance(node);
    }
};