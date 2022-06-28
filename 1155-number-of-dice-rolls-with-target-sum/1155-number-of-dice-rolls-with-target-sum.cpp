class Solution {
public:
    int rec(int n,int target,int mod,int k,vector<vector<int>> &dp){
        if(n==0 && target==0) return 1;
        if(target<0 || n<=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int take=0;
        for(int j=1;j<=k && target>=j;j++){
            take=((take)%mod+rec(n-1,target-j,mod,k,dp)%mod)%mod;
        }
        return dp[n][target]=take;
    }
    int numRollsToTarget(int n, int k, int target) {
        int mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return rec(n,target,mod,k,dp);
    }
};