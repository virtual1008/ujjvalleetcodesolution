class Solution {
public:
    int maxProfit(int t, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(t+1,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=t;k++){
                    if(j){
                        dp[i][k][j]=max(-prices[i]+dp[i+1][k][1-j],dp[i+1][k][j]);
                    }else{
                        dp[i][k][j]=max(prices[i]+dp[i+1][k-1][1-j],dp[i+1][k][j]);
                    }
                }
            }
        }
        return dp[0][t][1];
    }
};