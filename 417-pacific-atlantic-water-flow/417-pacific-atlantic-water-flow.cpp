class Solution {
public:
    int n,m;
    void BFS1(int i,int j,vector<vector<int>> & heights,vector<vector<int>> &dp,vector<vector<int>> &vis){
       if(vis[i][j]==0){
           vis[i][j]=1;;
         dp[i][j]=1;
          if(i>0 && heights[i-1][j]>=heights[i][j]){
             //if(dp[i-1][j]!=-1) return ;
              BFS1(i-1,j,heights,dp,vis);   
          }
          if(i<n-1 && heights[i+1][j]>=heights[i][j]){
            //if(dp[i+1][j]!=-1) return ;
              BFS1(i+1,j,heights,dp,vis);   
          }
         if(j>0 && heights[i][j-1]>=heights[i][j]){
            //if(dp[i+1][j]!=-1) return ;
              BFS1(i,j-1,heights,dp,vis);   
          }
          if(j<m-1 && heights[i][j+1]>=heights[i][j]){
             //if(dp[i][j+1]!=-1) return ;
             BFS1(i,j+1,heights,dp,vis);
         }
       }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>> dp1(n,vector<int>(m,-1));
        vector<vector<int>> dp2(n,vector<int>(m,-1));
        vector<vector<int>> vis1(n,vector<int>(m,0));
        vector<vector<int>> vis2(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dp1[i][0]=true;
            dp2[i][m-1]=true;
            BFS1(i,0,heights,dp1,vis1);
            BFS1(i,m-1,heights,dp2,vis2);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) vis1[i][j]=vis2[i][j]=0;
        }
        for(int i=0;i<m;i++){
            dp1[0][i]=true;
            dp2[n-1][i]=true;
            BFS1(0,i,heights,dp1,vis1);
            BFS1(n-1,i,heights,dp2,vis2);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp1[i][j]==1 && dp2[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};