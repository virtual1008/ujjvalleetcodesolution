class Solution {
public:
    void parentmapping(TreeNode* root,map<TreeNode*,TreeNode*> & parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tnode=q.front();
            q.pop();
            if(tnode->left){
                parent[tnode->left]=tnode;
                q.push(tnode->left);
            }
            if(tnode->right){
                parent[tnode->right]=tnode;
                q.push(tnode->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       map<TreeNode*,TreeNode*> ma;
        parentmapping(root,ma);
        map<TreeNode* ,bool> visited;
        vector<int> ans;
        int cnt=0;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int n=q.size();
            if(cnt++==k) break;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(ma[node] && !visited[ma[node]]){
                    q.push(ma[node]);
                    visited[ma[node]]=true;
                }
            }
        }
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};