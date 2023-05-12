class Solution {
public:
    long long rec(int i,vector<vector<int>> & questions,vector<long long> &dp){
        if(i>=questions.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long pick=questions[i][0]+rec(i+questions[i][1]+1,questions,dp);
        long long skip=rec(i+1,questions,dp);
        return dp[i]=max(pick,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return rec(0,questions,dp);
    }
};