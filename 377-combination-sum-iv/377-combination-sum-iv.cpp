class Solution {
public:
    int rec(int i,int target,vector<int> nums,vector<vector<int>> &dp){
        if(target==0) return 1;
        if(target<0 || i<0) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int ans=rec(i-1,target,nums,dp);
        if(nums[i]<=target){
            ans+=rec(nums.size()-1,target-nums[i],nums,dp);
        }
        return dp[i][target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int> (target+1,-1));
        return rec(nums.size()-1,target,nums,dp);
    }
};