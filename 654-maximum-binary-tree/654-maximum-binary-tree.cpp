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
    TreeNode* rec(int l,int r,vector<int>&nums){
        if(l>r) return NULL;
         int maxi=*max_element(nums.begin()+l,nums.begin()+r+1);
         int index1=mp[maxi];
         TreeNode* root=new TreeNode(maxi);
         root->left=rec(l,index1-1,nums);
         root->right=rec(index1+1,r,nums);
         return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
         for(int i=0;i<nums.size();i++){
             mp[nums[i]]=i;
         }
         return rec(0,nums.size()-1,nums);
    }
};