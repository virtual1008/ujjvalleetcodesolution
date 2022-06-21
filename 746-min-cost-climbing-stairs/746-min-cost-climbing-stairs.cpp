class Solution {
public:
    int rec(int i,vector<int> cost,vector<int> &dp){
        int n=cost.size();
       if(i>=n) return 0;
      // if(i==n) return 0;
       if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(rec(i+1,cost,dp),rec(i+2,cost,dp));
    }
        
    int minCostClimbingStairs(vector<int>& cost) {
        reverse(cost.begin(),cost.end());
        cost.push_back(0);
         reverse(cost.begin(),cost.end());
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return rec(0,cost,dp);
        
    }
};