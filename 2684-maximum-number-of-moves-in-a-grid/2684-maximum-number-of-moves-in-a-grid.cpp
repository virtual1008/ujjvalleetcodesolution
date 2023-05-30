class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int j,vector<vector<int>> & grid){
        if(i>=grid.size() || i<0 || j>=grid[0].size()) return 0;
        int front=0,left=0,right=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j+1<grid[0].size() && grid[i][j]<grid[i][j+1]) front=1+rec(i,j+1,grid);
        if(j+1<grid[0].size() && i-1>=0 && grid[i][j]<grid[i-1][j+1]) left=1+rec(i-1,j+1,grid);
        if(j+1<grid[0].size() && i+1<grid.size() && grid[i][j]<grid[i+1][j+1]) right=1+rec(i+1,j+1,grid);
        return dp[i][j]=max({left,right,front});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans=0;
        dp=vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            ans=max(ans,rec(i,0,grid));
        }
        return ans;
    }
};