class Solution {
public:
    void rec(int i,int j,int n,int m,vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
        grid[i][j]='0';
        rec(i+1,j,n,m,grid);
        rec(i-1,j,n,m,grid);
        rec(i,j+1,n,m,grid);
        rec(i,j-1,n,m,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    rec(i,j,n,m,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};