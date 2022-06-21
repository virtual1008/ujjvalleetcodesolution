class Solution {
public:
    int rec(bool buy,int i,vector<int> prices,vector<vector<int>> &dp){
        int n=prices.size();
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+rec(0,i+1,prices,dp),rec(1,i+1,prices,dp));
        }else{
            return dp[i][buy]=max(prices[i]+rec(1,i+2,prices,dp),rec(0,i+1,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return rec(1,0,prices,dp);
    }
};