class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i==triangle.size()-1)
            return triangle[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down = triangle[i][j]+rec(i+1,j,triangle,dp);
        int diagonal = triangle[i][j]+rec(i+1,j+1,triangle,dp);
        
        return dp[i][j] = min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return rec(0,0,triangle,dp);
    }
};