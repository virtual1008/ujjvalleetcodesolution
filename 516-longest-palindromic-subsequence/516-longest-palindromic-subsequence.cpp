class Solution {
public:
    int rec(int i,int j,string s,string t,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=1+rec(i-1,j-1,s,t,dp);
        }else{
            return dp[i][j]=max(rec(i-1,j,s,t,dp),rec(i,j-1,s,t,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
       // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //return rec(n-1,n-1,s,t,dp);
        vector<int> curr(n+1,0),temp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+temp[j-1];
                    //dp[i][j]=1+dp[i-1][j-1];
                }else{
                    curr[j]=max(curr[j-1],temp[j]);
                    //dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
            temp=curr;
        }
        return curr[n];
    }
};