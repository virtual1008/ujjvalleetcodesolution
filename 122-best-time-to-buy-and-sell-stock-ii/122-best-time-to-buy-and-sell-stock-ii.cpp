class Solution {
public:
    int rec(int i,bool buy,vector<int> prices,vector<vector<int>> &dp){
        int n=prices.size();
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        
        if(buy){
            return dp[i][buy]=max(-prices[i]+rec(i+1,false,prices,dp),rec(i+1,true,prices,dp));
        }else{
            return dp[i][buy]=max(prices[i]+rec(i+1,true,prices,dp),rec(i+1,false,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
      //  vector<int> dp(prices.size(),-1);
        int n=prices.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        dp[n][0]=dp[n][1]=0;
        //return rec(0,true,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return (int)dp[0][1];
    }
};