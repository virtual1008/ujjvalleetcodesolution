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
    int height(TreeNode* node){
        if(node==NULL) return 0;
        int left=height(node->left);
        int right=height(node->right);
        return 1+max(left,right);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root)-1;
        int n=pow(2,h+1)-1;
        queue<pair<pair<int,int>,TreeNode*>> q;
        vector<vector<string>> ans(h+1,vector<string>(n,""));
        q.push({{0,n},root});
        int d=0;
        while(!q.empty()){
            int si=q.size();
            for(int i=0;i<si;i++){
                 auto it=q.front();
                 q.pop();
                 int l=it.first.first;
                 int r=it.first.second;
                 TreeNode* node=it.second;
                 int mid=l+(r-l)/2;
                 ans[d][mid]=to_string(node->val);
                if(node->left){
                    q.push({{l,mid-1},node->left});
                }
                if(node->right){
                    q.push({{mid+1,r},node->right});
                }
            }
            d++;
        }
        return ans;
        
    }
};