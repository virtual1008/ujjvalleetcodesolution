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
    map<string,vector<TreeNode*>> mp;
    vector<TreeNode*> ans;
    string dfs(TreeNode* node){
        if(node==NULL) return "(N)";
        string temp="("+to_string(node->val);
        if(node->left){
            temp+=dfs(node->left);
        }else temp+="(N)";
        if(node->right){
            temp+=dfs(node->right);
        }else temp+="(N)";
        temp+=")";
        mp[temp].push_back(node);
        if(mp[temp].size()==2) ans.push_back(node);
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        //for(auto it)
        return ans;
    }
};