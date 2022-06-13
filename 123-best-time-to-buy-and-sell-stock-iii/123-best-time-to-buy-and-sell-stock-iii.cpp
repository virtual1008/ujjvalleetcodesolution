class Solution {
public:
    int rec(int i,bool buy,int cnt,vector<int> prices,vector<vector<vector<int>>> &dp){
        if(i>=prices.size()) return 0;
        if(cnt>=2) return 0;
        if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt];
        if(buy){
            return dp[i][buy][cnt]=max(-prices[i]+rec(i+1,false,cnt,prices,dp),rec(i+1,true,cnt,prices,dp));
        }else{
            return dp[i][buy][cnt]=max(prices[i]+rec(i+1,true,cnt+1,prices,dp),rec(i+1,false,cnt,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
         for(int i=n-1;i>=0;i--){
             for(int j=0;j<=1;j++){
                 for(int k=1;k<=2;k++){
                     if(j){
                         dp[i][j][k]=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                     }else{
                         dp[i][j][k]=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                     }
                 }
             }
         }
        return dp[0][1][2];
        //return rec(0,true,0,prices,dp);
    }
};