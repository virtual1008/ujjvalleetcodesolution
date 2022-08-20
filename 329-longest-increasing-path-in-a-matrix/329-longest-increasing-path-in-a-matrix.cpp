class Solution {
public:
    int n,m;
    int dfs(int i,int j,int pre,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=n || j>=m || pre>=matrix[i][j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int temp=0;
        int val;
        val=dfs(i+1,j,matrix[i][j],matrix,dp);
        temp=max(1+val,temp);
        val=dfs(i-1,j,matrix[i][j],matrix,dp);
        temp=max(1+val,temp);
        val=dfs(i,j+1,matrix[i][j],matrix,dp);
        temp=max(1+val,temp);
        val=dfs(i,j-1,matrix[i][j],matrix,dp);
        temp=max(1+val,temp);
        return dp[i][j]=temp;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]!=-1){
                    ans=max(ans,dp[i][j]);
                }else{
                    int val=dfs(i,j,-1,matrix,dp);
                    ans=max(ans,val);
                }
            }
        }
        return ans;
    }
};