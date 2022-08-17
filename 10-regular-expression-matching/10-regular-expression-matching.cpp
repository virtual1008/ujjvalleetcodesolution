class Solution {
public:
   vector<vector<int>> dp;
    int rec(int i,int j,string s,string p){
        if(i<0 && j<0 ) return true;
        if(j<0) return false;
        if(i<0){
            while(j>=0){
                if(p[j]=='*') j--;
                else return  false;
                j--;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='.') return rec(i-1,j-1,s,p);
        else if(p[j]=='*'){
            bool result=rec(i,j-2,s,p);
            if(s[i]==p[j-1] || p[j-1]=='.') result = result || rec(i-1,j,s,p);
            return dp[i][j]=result;
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return rec(s.size()-1,p.size()-1,s,p);
    }
};