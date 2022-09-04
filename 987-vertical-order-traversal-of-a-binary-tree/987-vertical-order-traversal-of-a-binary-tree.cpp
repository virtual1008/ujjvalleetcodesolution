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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,vector<pair<int,int>>> mp;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                int x=it.second.first;
                int y=it.second.second;
                mp[x].push_back({y,node->val});
                if(node->left){
                    q.push({node->left,{x-1,y+1}});  
                }
                if(node->right){
                    q.push({node->right,{x+1,y+1}});  
                }
            }
        }
        for(auto it:mp){
            cout<<it.first<<"->";
            auto cv=it.second;
            sort(cv.begin(),cv.end());
            vector<int> temp;
            for(auto ele:cv){
               // cout<<"("<<ele.first<<","<<ele.second<<")";
                temp.push_back(ele.second);
            }
            //cout<<"\n";
            //sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
        
    }
};