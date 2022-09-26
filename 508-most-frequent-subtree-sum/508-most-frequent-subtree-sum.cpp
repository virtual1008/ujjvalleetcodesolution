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
    map<int,int> mp;
    int maxi=0;
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        int left=0,right=0;
        left+=rec(root->left);
        right+=rec(root->right);
        int sum=left+right+root->val;
        mp[sum]++;
        maxi=max(maxi,mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        rec(root);
        vector<int> ans;
        for(auto it:mp){
            if(it.second==maxi) ans.push_back(it.first);
        }
        return ans;
        
    }
};