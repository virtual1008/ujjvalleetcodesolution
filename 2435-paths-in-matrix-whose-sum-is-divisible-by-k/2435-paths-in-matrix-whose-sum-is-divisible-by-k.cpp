class Solution {
public:
    vector<vector<vector<int>>> dp;
    int kmod=1e9+7;
    int rec(int i,int j,int mod,int &k,vector<vector<int>> & grid){
        if(i>=grid.size() || j>=grid[0].size()) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            if((mod+grid[i][j])%k==0) return 1;
            return 0;
        }
        if(dp[i][j][mod]!=-1) return dp[i][j][mod];
        int down=rec(i,j+1,(mod+grid[i][j])%k,k,grid);
        int right=rec(i+1,j,(mod+grid[i][j])%k,k,grid);
        return dp[i][j][mod]=((down)%kmod+(right)%kmod)%kmod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp=vector<vector<vector<int>>>(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k,-1)));
        return rec(0,0,0,k,grid);
    }
};