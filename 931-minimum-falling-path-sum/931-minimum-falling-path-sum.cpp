class Solution {
public:
    int rec(int i,int j,int n,int m,vector<vector<int>> matrix,vector<vector<int>> &dp){
        if(i>=n || j>=m || j<0) return 1e6;
        if(i==n-1 ) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<n;k++){
            int l=rec(i+1,k-1,n,m,matrix,dp);
            int b=rec(i+1,k,n,m,matrix,dp);
            int r=rec(i+1,k+1,n,m,matrix,dp);
            dp[i][k]=matrix[i][k]+min({l,b,r});
        }
        return dp[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      //  int c =rec(0,0,n,m,matrix,dp);
        int ans=INT_MAX;
        for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        if(n==1){
           for(int i=0;i<m;i++){
               ans=min(ans,matrix[n-1][i]);
           }
            return ans;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int a=INT_MAX;
                if(j>0) a=dp[i-1][j-1];
                int b=INT_MAX;
                if(j<m-1) b=dp[i-1][j+1];
                int c=dp[i-1][j];
                dp[i][j]=matrix[i][j]+min({a,b,c});
                if(i==n-1) ans=min(ans,dp[i][j]);
            }
        }
        
        return ans;
        
    }
};