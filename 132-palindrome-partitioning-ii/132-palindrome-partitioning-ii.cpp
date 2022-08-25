class Solution {
public:
    vector<int> dp;
    bool ispallindrom(int i,int j,string &str){
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int rec(int i,string &s,int n){
        int ans=INT_MAX;
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<n;j++){
            if(ispallindrom(i,j,s)){
                int cnt=1+rec(j+1,s,n);
                ans=min(ans,cnt);
            }
            
        }
        return dp[i]=ans;
    }
    int minCut(string s){
        int n=s.size();
        dp=vector<int>(n+1,-1);
        return rec(0,s,n)-1;
    }
};