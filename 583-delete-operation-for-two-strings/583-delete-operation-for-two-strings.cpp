class Solution {
public:
    int rec(string s1,string s2,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+rec(s1,s2,i-1,j-1,dp);
        }else{
            return dp[i][j]=max(rec(s1,s2,i,j-1,dp),rec(s1,s2,i-1,j,dp));
        }
    }
    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int c=rec(s1,s2,n-1,m-1,dp);
        return n+m-2*c;
    }
};