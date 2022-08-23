class Solution {
public:
    vector<vector<int>> dp;
    bool rec(int i,int j,string &s,vector<string> &v){
        if(j>=s.size()){
            string str=s.substr(i,s.size()-i);
          //  cout<<str;
           // cout<<"\n";
            return find(v.begin(),v.end(),str)!=v.end();
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool c=rec(i,j+1,s,v);
        string str=s.substr(i,j-i);
        //cout<<str;
       // cout<<"\n";
        if(find(v.begin(),v.end(),str)!=v.end()) c=c||rec(j,j+1,s,v);
        return dp[i][j]=c;
        
    }
    bool wordBreak(string s, vector<string>& v) {
        int n=s.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return rec(0,1,s,v);
    }
};