class Solution {
public:
    vector<vector<long long>> dp;
    long long rec(int i,long long amount,vector<int> &coins){
        if(i<0){
            if(amount==0) return 0;
            return INT_MAX;
        }
        if(amount<0) return INT_MAX;
        if(dp[i][amount]!=-1) return dp[i][amount];
        if(coins[i]<=amount){
            return dp[i][amount]=min(1LL+rec(i,amount-coins[i],coins),rec(i-1,amount,coins));
        }else{
            return dp[i][amount]=rec(i-1,amount,coins);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
       dp=vector<vector<long long>>(coins.size()+1,vector<long long>(amount+1,-1));
        long long c=rec(coins.size()-1,(long long)amount,coins);
        return c>=INT_MAX?-1:c;
    }
};