class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> temp(m+1,0);
        temp[0]=1;
        vector<double> curr(m+1,0);
        curr[0]=1;
        
        //vector<vector<double>> dp(n+1,vector<double>(m+1,0));
       // for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=temp[j-1]+temp[j];
                else curr[j]=temp[j];
            }
            temp=curr;
        }
       return  curr[m];
    }
};