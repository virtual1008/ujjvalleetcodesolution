class Solution {
public:
    vector<vector<int>> dp;
    bool rec(int n,int k){
        if(n==0) return 1-k;
        int ans=1-k;
        if(dp[n][k]!=-1) return dp[n][k];
        for(int i=1;i*i<=n;i++){
            int cv=rec(n-i*i,1-k);
            if(k){
                if(cv==1){
                    ans=1;
                    break;
                }
            }else{
                if(cv==0){
                    ans=0;
                    break;
                }
            }
        }
        return dp[n][k]=ans;
    }
    bool winnerSquareGame(int n) {
        dp=vector<vector<int>>(n+1,vector<int>(2,-1));
        return rec(n,1);
    }
};