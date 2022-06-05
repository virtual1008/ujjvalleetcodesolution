class Solution {
public:
    int recur(string s,int idx,vector<int> &dp)
    {
        if(idx==s.size())
            return 1;
        if(s[idx]=='0')
            return 0;
        if(idx==s.size()-1)
            return 1;
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        string temp=s.substr(idx,2);
        
        int op1=recur(s,idx+1,dp);
        int op2=(stoi(temp)>=1 and stoi(temp)<=26)?recur(s,idx+2,dp):0;
        
        return dp[idx]=op1+op2;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);
        return recur(s,0,dp);
    }
};