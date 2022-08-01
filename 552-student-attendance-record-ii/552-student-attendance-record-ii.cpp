class Solution {
public:
    int mod=1e9+7;
    int dp[100001][10][10];
    int rec(int abs,int late,int n){
        if(abs>1 || late>=3) return 0;
        if(n==0) return 1;
        if(dp[n][abs][late]!=-1) return dp[n][abs][late];
        int a=rec(abs+1,0,n-1)%mod;
        int b=rec(abs,late+1,n-1)%mod;
        int c=rec(abs,0,n-1)%mod;
        return  dp[n][abs][late]=((a%mod+b%mod)%mod+c%mod)%mod;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n);
    }
};