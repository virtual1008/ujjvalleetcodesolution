class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,bool flag,vector<int> &prices){
        if(i>=prices.size()) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        if(flag){
            return dp[i][flag]=max(-prices[i]+rec(i+1,1-flag,prices),rec(i+1,flag,prices));
        }else{
            return dp[i][flag]=max(prices[i]+rec(i+1,1-flag,prices),rec(i+1,flag,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        dp=vector<vector<int>>(prices.size(),vector<int>(2,-1));
        return rec(0,true,prices);
    }
};