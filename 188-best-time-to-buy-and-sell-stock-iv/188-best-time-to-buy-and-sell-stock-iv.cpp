class Solution {
public:
    vector<vector<vector<int>>> dp;
    int  rec(int i,int k,bool buy,vector<int> &prices){
        if(k<=0) return 0;
        if(i>=prices.size()) return 0;
        if(dp[i][k][buy]!=-1) return dp[i][k][buy];
        if(buy){
            return dp[i][k][buy]=max(-prices[i]+rec(i+1,k,1-buy,prices),rec(i+1,k,buy,prices));
        }else{
            return dp[i][k][buy]=max(prices[i]+rec(i+1,k-1,1-buy,prices),rec(i+1,k,buy,prices));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        dp=vector<vector<vector<int>>>(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return rec(0,k,true,prices);
    }
};