class Solution {
public:
    int e = 1e9 +7;
    long long int dp[51][51][51];
    int rec(int m,int n,int i,int j,int move){
        if(i<0 || j<0 || i>=m || j>=n) return 1;
        if(move==0) return 0;
        if(dp[i][j][move]!=-1) return dp[i][j][move];
        return dp[i][j][move]=(((rec(m,n,i-1,j,move-1)%e+rec(m,n,i+1,j,move-1)%e)%e+rec(m,n,i,j-1,move-1)%e)%e+rec(m,n,i,j+1,move-1)%e)%e;
    }
    int findPaths(int m, int n, int move, int r, int c) {
         memset(dp,-1,sizeof(dp));
        return rec(m,n,r,c,move);
    }
};