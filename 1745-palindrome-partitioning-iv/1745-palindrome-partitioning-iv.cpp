class Solution {
public:
    int dp[2003][2003];
   bool ispallindrom(int i, int j,string &s){
    if(i>=j) return 1;
        
    if(dp[i][j]!=-1) return dp[i][j];
    
    if (s[i] == s[j]) return dp[i][j] = ispallindrom( i + 1, j - 1,s);
		return dp[i][j] = 0;
    
}
    bool checkPartitioning(string str) {
       int n=str.size();
        memset(dp,-1,sizeof(dp));
        if(n==3) return true;
       for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n-1;j++){
               if(ispallindrom(0,i,str) && ispallindrom(i+1,j,str) && ispallindrom(j+1,n-1,str)) return true;
           }
       }
        return false;
    }
};