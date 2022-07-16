class Solution {
public:
    bool rec(int i,int j,vector<int> nums,vector<vector<int>> &dp){
        if(j==0) return true;
        if(i<0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool take=false;
        if(nums[i]<=j){
            take=rec(i-1,j-nums[i],nums,dp);
        }
        bool ntake=rec(i-1,j,nums,dp);
        return dp[i][j]=take||ntake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum%2!=0) return false;
        sum/=2;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        //return rec(n-1,sum,nums,dp);
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                bool take=false,ntake=false;
                if(j>=nums[i]) take=dp[i-1][j-nums[i]];
                ntake=dp[i-1][j];
                dp[i][j]=take||ntake;
            }
        }
        return dp[n-1][sum];
    }
};