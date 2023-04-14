class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int j,string &s){
        if(i>=s.size() || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=1+rec(i+1,j-1,s);
        else return dp[i][j]=max(rec(i+1,j,s),rec(i,j-1,s));
    }
    int longestPalindromeSubseq(string s) {
        dp=vector<vector<int>>(s.size()+1,vector<int>(s.size()+1,-1));
        return rec(0,s.size()-1,s);
    }
};