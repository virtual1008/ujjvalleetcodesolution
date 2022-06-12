class Solution {
public:
    int rec(int i,int j,string s1,string s2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=rec(i-1,j-1,s1,s2,dp);
        else return dp[i][j]=1+min(rec(i-1,j-1,s1,s2,dp),min(rec(i-1,j,s1,s2,dp),rec(i,j-1,s1,s2,dp)));
        
    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int> pre(m+1,0),curr(m+1,0);
        for(int i=0;i<=m;i++) pre[i]=i;
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=pre[j-1];
                }else{
                    curr[j]=1+min(pre[j-1],min(pre[j],curr[j-1]));
                }
            }
            pre=curr;
        }
        return pre[m];
    }
};