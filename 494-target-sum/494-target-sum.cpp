class Solution {
public:
    int rec(int i,int sum,vector<int> nums,vector<vector<int>> &dp){
        if(i>=nums.size()) {
            if(sum==0) return 1;
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
       // if(sum==0) return 1;
        int take=0;
        if(sum>=nums[i])take=rec(i+1,sum-nums[i],nums,dp);
        int ntake=rec(i+1,sum,nums,dp);
        return dp[i][sum]=take+ntake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums) sum+=it;
        //sort(nums.begin(),nums.end());
        int d=sum+target;
        //if(d<0) return 0;
        if(d%2!=0 ||d<0) return 0;
        d/=2;
        vector<vector<int>> dp(nums.size(),vector<int>(d+1,-1));
        return rec(0,d,nums,dp);
        
    }
};