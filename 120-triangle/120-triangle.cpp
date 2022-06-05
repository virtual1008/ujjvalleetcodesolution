class Solution {
public:
    /*int rec(int i,int j,vector<vector<int>> & store,vector<vector<int>> & dp,int n){
        if(i==n-1) return store[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int a=store[i][j]+rec(i+1,j,store,dp,n);
        int b=store[i][j]+rec(i+1,j+1,store,dp,n);
        return dp[i][j]=min(a,b);
    }*/
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int up=dp[i+1][j];
                int dig=dp[i+1][j+1];
                dp[i][j]=min(up,dig)+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};