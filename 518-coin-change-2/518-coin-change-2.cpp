class Solution {
public:
    int rec(int amount,int i,vector<int> coins,vector<vector<int>> &dp){
        if(i<0) return 0;
        if(amount==0) return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];
        if(coins[i]<=amount) return dp[i][amount]=(rec(amount-coins[i],i,coins,dp)+rec(amount,i-1,coins,dp));
        else return dp[i][amount]=rec(amount,i-1,coins,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return rec(amount,coins.size()-1,coins,dp);
    }
};