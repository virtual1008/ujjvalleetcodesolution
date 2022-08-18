class Solution {
public:
    vector<vector<bool>> dp;
   // bool rec(int i,int j,string s,string p){
     //   if(i>=s.size() && j>=p.size()) return true;
      //  if(j>=p.size()) return false;
       // if(i>=s.size()){
         //   while(j<p.size()){
           //     if(p[j]!='*') return false;
             //   j++;
      //      }
       //     return true;
     //   }
    //    if(dp[i][j]!=-1) return dp[i][j];
     //   if(s[i]==p[j] || p[j]=='?') return dp[i][j]=rec(i+1,j+1,s,p);
    //    else if(p[j]=='*'){
    //        return dp[i][j]=(rec(i+1,j+1,s,p) || rec(i+1,j,s,p) || rec(i,j+1,s,p));
      //  }else return false;
   // }
    bool isMatch(string s, string p) {
        s='#'+s;
        p='#'+p;
        int n=s.size();
        int m=p.size();
        dp=vector<vector<bool>>(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<m;i++){
            if(p[i]=='*') dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(s[i]==p[j] || p[j]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j]=='*') dp[i][j]=dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};