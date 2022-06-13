class Solution {
public:
    int rec(int i,int j,int k,vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(i>=prices.size()) return 0;
        if(k<=0) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(j){
            return dp[i][j][k]=max(-prices[i]+rec(i+1,0,k,prices,dp),rec(i+1,1,k,prices,dp));
        }else{
            return dp[i][j][k]=max(prices[i]+rec(i+1,1,k-1,prices,dp),rec(i+1,0,k,prices,dp));
        }
    }
    int maxProfit(int t, vector<int>& prices) {
        int n=prices.size();
        //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(t+1,0)));
        vector<vector<int>> cur(2,vector<int>(t+1,0)),pre(2,vector<int>(t+1,0));
         for(int i=n-1;i>=0;i--){
             for(int j=0;j<=1;j++){
                 for(int k=1;k<=t;k++){
                     if(j){
                         cur[j][k]=max(-prices[i]+pre[0][k],pre[1][k]);
                     }else{
                         cur[j][k]=max(prices[i]+pre[1][k-1],pre[0][k]);
                     }
                 }
             }
             pre=cur;
         }
        return cur[1][t];
    }
};