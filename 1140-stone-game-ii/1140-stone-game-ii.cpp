class Solution {
public:
    int n;
    int dp[101][101];
    int rec(int i,int m,vector<int> pre){
        if(i>=n) return 0;
        int ans=INT_MIN,cnt=0,nm;
        if(dp[i][m]!=-1) return dp[i][m];
        for(int j=i;j<n&&j<(i+2*m);j++){
            nm=max(j-i+1,m);
            int left=rec(j+1,nm,pre);
            int temp=(pre[j+1]-pre[i])+(pre[n]-pre[j+1])-left;
            ans=max(ans,temp);
        }
        return dp[i][m]=ans;
        
    }
    int stoneGameII(vector<int>& piles) {
        n = size(piles);
        memset(dp, -1, sizeof(dp));
        vector<int>pre(n+1, 0);
        
        for(int i = 1; i<n; i++)
            pre[i] = pre[i-1] + piles[i-1];
        
        pre[n] = pre[n-1] + piles[n-1];
        return rec(0,1,pre);
    }
};