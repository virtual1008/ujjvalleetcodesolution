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
    map<pair<TreeNode*,pair<bool,bool>>,int> dp;
    int rec(TreeNode* root,bool cam,bool parcam){
        if(root==NULL){
            if(cam) return 1e6;
            else return 0;
        }
        if(root->left==NULL && root->right==NULL){
            if(cam) return 1;
            else{
                if(parcam) return 0;
                else 1e9;
            }
        }
        if(dp.find({root,{cam,parcam}})!=dp.end()) return dp[{root,{cam,parcam}}];
        if(cam){
            return dp[{root,{cam,parcam}}]=1+min(rec(root->left,0,1),rec(root->left,1,1))+
                min(rec(root->right,0,1),rec(root->right,1,1));
        }else{
            if(parcam){
                return dp[{root,{cam,parcam}}]=min(rec(root->left,0,0),rec(root->left,1,0))+
                    min(rec(root->right,0,0),rec(root->right,1,0));
            }else{
                int op1=rec(root->left,1,0)+min(rec(root->right,0,0),rec(root->right,1,0));
                int op2=rec(root->right,1,0)+min(rec(root->left,0,0),rec(root->left,1,0));
                 return dp[{root,{cam,parcam}}]=min(op1,op2);
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        return min(rec(root,0,0),rec(root,1,0));
    }
};