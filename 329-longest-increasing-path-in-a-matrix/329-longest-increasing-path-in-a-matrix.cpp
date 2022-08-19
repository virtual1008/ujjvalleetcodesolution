class Solution {
public: 
    int n,m;
   // vector<vector<int>> vis;
    int dfs(int i,int j,vector<vector<int>>& matrix,int cnt,int pre,vector<vector<int>>& vis){
        if(i<0 || j<0 || i>=n || j>=m || pre>=matrix[i][j] ){
             
            return 0;
        }
        if(vis[i][j]!=-1)
            return vis[i][j]; 
        int temp=0;
        int val;
        val=dfs(i+1,j,matrix,cnt+1,matrix[i][j],vis);
        temp=max(temp,1+val);
       val= dfs(i-1,j,matrix,cnt+1,matrix[i][j],vis);
        temp=max(temp,1+val);
        val=dfs(i,j+1,matrix,cnt+1,matrix[i][j],vis);
        temp=max(temp,1+val);
        val=dfs(i,j-1,matrix,cnt+1,matrix[i][j],vis);
        temp=max(temp,1+val);
        return vis[i][j]=temp;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         n=matrix.size();
         m=matrix[0].size();
        int ans=0;
                 vector<vector<int>> vis(n,vector<int>(m,-1));
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(vis[i][j]==1)
                     continue;
                 int val=dfs(i,j,matrix,0,-1,vis);
                ans=max(ans,val);
             }
         }
        return ans;
    }
};