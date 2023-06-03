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
    map<int,int> mp,height;
    map<int,set<pair<int,int>>> mpair;
    int rec(TreeNode* node,int level){
        if(node==NULL) return 0;
        mp[node->val]=level;
        int left=rec(node->left,level+1);
        int right=rec(node->right,level+1);
        int c=1+max(left,right);
        int d=level+max(left,right);
        height[node->val]=d;
        mpair[level].insert({d,node->val});
        return c;
        
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        rec(root,0);
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int level=mp[queries[i]];
            if(mpair[level].size()>1){
                int h=height[queries[i]];
                //auto it=lower_bound(mpair[level].begin(),mpair[level].end(),{h,-1});
                auto it=mpair[level].lower_bound({h,-1});
                auto p=*it;
                mpair[level].erase(it);
                auto c=*(mpair[level].rbegin());
                ans.push_back(c.first);
                mpair[level].insert(p);
            }else{
                ans.push_back(level-1);
            }
        }
        return ans;
    }
};


















