class Solution {
public:
    vector<vector<int>> dp;
    int rec(int start,int end,vector<int> & piles){
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int l=piles[start]-rec(start+1,end,piles);
        int r=piles[end]-rec(start,end-1,piles);
        return dp[start][end]=max(l,r);
    }
    bool stoneGame(vector<int>& piles) {
        dp=vector<vector<int>>(piles.size(),vector<int>(piles.size(),-1));
        int c=rec(0,piles.size()-1,piles);
        return c>0;
    }
};