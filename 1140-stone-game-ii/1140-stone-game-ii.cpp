class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,vector<int> p,int m){
        if(i>=p.size()) return 0;
        int ans=INT_MIN;
        if(dp[i][m]!=INT_MAX) return dp[i][m];
        int t=0;
        for(int j=0;j<2*m;j++){
            if(i+j<p.size()) t+=p[i+j];
            ans=max(ans,t-rec(i+j+1,p,max(m,j+1)));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& p) {
        int sum=0;
        for(auto it:p) sum+=it;
        int n=p.size();
        dp=vector<vector<int>>(n+1,vector<int>(2*n+1,INT_MAX));
        int diff=rec(0,p,1);
        return (sum+diff)/2;
    }
};