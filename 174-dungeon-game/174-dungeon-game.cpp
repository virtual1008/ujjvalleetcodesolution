class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int j,vector<vector<int>> & v){
        if(i>=v.size() || j>=v[0].size()) return 1e7;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        if(i==v.size()-1 && j==v[0].size()-1) return v[i][j]>0?1:-v[i][j]+1;
        return dp[i][j]=max(1,-v[i][j]+min(rec(i+1,j,v),rec(i,j+1,v)));
    }
    int calculateMinimumHP(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        dp=vector<vector<int>>(n,vector<int>(m,INT_MAX));
        return rec(0,0,v);
    }
};