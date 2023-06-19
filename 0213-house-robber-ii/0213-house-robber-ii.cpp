class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int end,vector<int> &nums){
        if(i==end || i>=nums.size()) return 0;
        if(dp[i][end]!=-1) return dp[i][end];
        int l=nums[i]+rec(i+2,end,nums);
        int r=rec(i+1,end,nums);
        return dp[i][end]=max(l,r);
    }
    int rob(vector<int>& nums) {
        dp=vector<vector<int>>(nums.size()+3,vector<int>(nums.size()+3,-1));
        if(nums.size()==1) return nums[0];
        return max(rec(0,nums.size()-1,nums),rec(1,nums.size()+1,nums));
    }
};