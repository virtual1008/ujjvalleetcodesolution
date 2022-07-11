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
    vector<int> maping(TreeNode* root){
       
        vector<int> ans;
         if(root==NULL) return ans;
         map<int,TreeNode*> ma;
         queue<pair<int,TreeNode*>> q;
         q.push({0,root});
         int level=0;
         while(!q.empty()){
             int n=q.size();
             for(int i=0;i<n;i++){
                 auto it=q.front();
                 q.pop();
                 ma[it.first]=it.second;
                 if(it.second->left){
                     q.push({level+1,it.second->left});
                 }
                 if(it.second->right){
                     q.push({level+1,it.second->right});
                 }
             }
             level++;
         }
        for(auto i:ma){
            ans.push_back(i.second->val);
        }
        return ans;
        
    }
    vector<int> rightSideView(TreeNode* root) {
        return maping(root);
    }
};