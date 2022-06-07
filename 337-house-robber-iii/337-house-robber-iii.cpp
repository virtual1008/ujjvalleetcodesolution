class Solution {
public:
    vector<int> helper(TreeNode* root){
       if(root == nullptr){
           return vector<int>(2,0);
       }
       vector<int> left = helper(root->left);
       vector<int> right = helper(root->right);
       vector<int> res(2,0);
       res[0] = left[1] + right[1] + root->val;
       res[1] = max(left[0],left[1]) + max(right[0],right[1]);
       return res;
    }
    
    int rob(TreeNode* root) {
        vector<int> y = helper(root);
        return max(y[0],y[1]);
    }
};