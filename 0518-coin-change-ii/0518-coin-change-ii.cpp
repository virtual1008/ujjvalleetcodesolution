class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int amount,vector<int> & coins){
       if(i<0){
          if(amount==0) return 1;
          return 0;
       }
       if(amount<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
       if(coins[i]<=amount){
           return dp[i][amount]=rec(i,amount-coins[i],coins)+rec(i-1,amount,coins);
       }else{
           return dp[i][amount]=rec(i-1,amount,coins);
       }
    }
    int change(int amount, vector<int>& coins) {
        dp=vector<vector<int>>(coins.size()+1,vector<int>(amount+1,-1));
        return rec(coins.size()-1,amount,coins);
    }
};