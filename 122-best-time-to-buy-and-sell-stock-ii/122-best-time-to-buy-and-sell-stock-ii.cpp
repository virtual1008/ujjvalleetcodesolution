class Solution {
public:
   /* int rec(int i,bool buy,vector<int> prices,vector<vector<int>> &dp){
        int n=prices.size();
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        
        if(buy){
            return dp[i][buy]=max(-prices[i]+rec(i+1,false,prices,dp),rec(i+1,true,prices,dp));
        }else{
            return dp[i][buy]=max(prices[i]+rec(i+1,true,prices,dp),rec(i+1,false,prices,dp));
        }
    }*/
    int maxProfit(vector<int>& prices) {
      //  vector<int> dp(prices.size(),-1);
        int n=prices.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        vector<long long> cur(2,0),pre(2,0);
        pre[0]=pre[1]=0;
        //return rec(0,true,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    cur[j]=max(-prices[i]+pre[0],pre[1]);
                }else{
                    cur[j]=max(prices[i]+pre[1],pre[0]);
                }
            }
            pre=cur;
        }
        return (int)cur[1];
    }
};