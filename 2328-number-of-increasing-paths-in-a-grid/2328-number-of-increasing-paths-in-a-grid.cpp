class Solution {
public:
    int n,m;
    int mod=1e9+7;
    vector<vector<int>> dp;
    vector<int> path={1,0,-1,0,1}; 
    int rec(int i,int j,vector<vector<int>>& grid){
        if(dp[i][j]!=-1) return dp[i][j];
        int val=1;
        for(int k=0;k<4;k++){
            if(i+path[k]>=0 && i+path[k]<n && j+(path[k+1])>=0 && j+path[k+1]<m && grid[i+path[k]][j+path[k+1]]>grid[i][j]){
               val=(val%mod+rec(i+path[k],j+path[k+1],grid)%mod)%mod;
            }
        }
        return dp[i][j]=val%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
          n=grid.size();
          m=grid[0].size();
          dp= vector<vector<int>>(n,vector<int>(m,-1));
          int ans=0;
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  ans=(ans%mod+rec(i,j,grid)%mod);
              }
          }
         return ans%mod;
         
    }
};