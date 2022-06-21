class Solution {
public:
    int rec(int i,bool buy,int fee,vector<int> prices,vector<vector<int>> &dp){
        int n=prices.size();
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+rec(i+1,0,fee,prices,dp),rec(i+1,1,fee,prices,dp));
        }else{
            return dp[i][buy]=max(prices[i]-fee+rec(i+1,1,fee,prices,dp),rec(i+1,0,fee,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
       // return rec(0,1,fee,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else dp[i][j]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};