class Solution {
public:

int dp[101][101];
bool solve(string &s1,string &s2,string &s3,int i,int j,int k,int n,int m,int sz){
    if(i==n && j==m && k==sz) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    bool c = false;
    if(i<n){
        if(s1[i]==s3[k]){
            c = c || solve(s1,s2,s3,i+1,j,k+1,n,m,sz);
        }
    }
    if(j<m){
        if(s2[j]==s3[k]){
            c = c || solve(s1,s2,s3,i,j+1,k+1,n,m,sz);
        }
    }
    return dp[i][j] = c;
}
bool isInterleave(string s1, string s2, string s3) {
    memset(dp,-1,sizeof(dp));
    if(s1.size()+s2.size()!=s3.size()) return 0;
    return solve(s1,s2,s3,0,0,0,s1.size(),s2.size(),s3.size());
}
};