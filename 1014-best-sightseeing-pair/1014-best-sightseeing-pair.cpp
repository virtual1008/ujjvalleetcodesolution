class Solution {
public:
    int rec(int i,vector<int> & values,int take,vector<vector<int>> &dp){
        if(take>1) return 0;
        if(i>=values.size()) return -1e6;
        if(dp[i][take]!=-1) return dp[i][take];
        int pick=values[i]+rec(i+1,values,take+1,dp);
        int npick=rec(i+1,values,take,dp);
        if(take==1){
            pick-=i;
        }else pick+=i;
        return dp[i][take]=max(pick,npick);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<vector<int>> dp(values.size(),vector<int>(3,-1));
         return rec(0,values,0,dp);
    }
};