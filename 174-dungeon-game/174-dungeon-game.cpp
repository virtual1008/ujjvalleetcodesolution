class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int j,vector<vector<int>> & v){
         if(dp[i][j]!=INT_MAX) return dp[i][j];
         if(i==v.size()-1 && j==v[0].size()-1) return v[i][j]>0 ? 1:abs(v[i][j])+1;
         else if(i==v.size()-1) return dp[i][j]=max(1,-v[i][j]+rec(i,j+1,v));
         else if(j==v[0].size()-1) return dp[i][j]=max(1,-v[i][j]+rec(i+1,j,v));
         else{
             return dp[i][j]=max(1,-v[i][j]+min(rec(i+1,j,v),rec(i,j+1,v)));
         }
    }
    int calculateMinimumHP(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,INT_MAX));
        return rec(0,0,v);
    }
};