class Solution {
public:
    vector<vector<vector<int>>> dp;
    int rec(int r1,int c1,int r2,vector<vector<int>> & grid){
        int c2=r1+c1-r2;
        if(c1>=grid.size() || c2>=grid.size() || r1>=grid.size() || r2>=grid.size() || grid[r1][c1]==-1 || grid[r2][c2]==-1) return -1e6;
        if(r1==grid.size()-1 && c1==grid.size()-1) return grid[r1][c1];
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
        int ans=grid[r1][c1];
        if(r1!=r2) ans+=grid[r2][c2];
        int temp=max(rec(r1+1,c1,r2+1,grid),rec(r1+1,c1,r2,grid));
        temp=max(temp,rec(r1,c1+1,r2,grid));
        temp=max(temp,rec(r1,c1+1,r2+1,grid));
        ans+=temp;
        return dp[r1][c1][r2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        dp=vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans=max(0,rec(0,0,0,grid));
        
        return ans;
    }
};