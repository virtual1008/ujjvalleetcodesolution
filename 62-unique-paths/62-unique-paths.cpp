class Solution {
public:
    int rec(int n,int m, vector<vector<int>> &dp){
        if(n<0 || m<0) return 0;
        if(n==0 && m==0) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m]=rec(n-1,m,dp)+rec(n,m-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        //memset(dp,-1,sizeof(dp));
        return rec(n-1,m-1,dp);
    }
};