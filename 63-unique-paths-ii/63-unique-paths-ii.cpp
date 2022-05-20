class Solution {
public:

int helper(vector<vector<int>>& v,int i,int j,vector<vector<int>> &dp)
{
int n = v.size();
int m = v[0].size();
if(i < 0 || i>=n || j<0 || j>=m || v[i][j] == 1) return 0;

if(dp[i][j] != -1) return dp[i][j];

if(i == n-1 && j == m-1) return 1;

int ans = 0;
ans += helper(v,i,j+1,dp) + helper(v,i+1,j,dp);

return dp[i][j] = ans;
}

int uniquePathsWithObstacles(vector<vector<int>>& v) {
    
    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    return helper(v,0,0,dp);
    
}
};