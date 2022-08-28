class Solution {
public:
   //vector<vector<int>> dp;
    int dp[1005][1005][2];
    int rec(int i,vector<vector<int>>& pairs,int prev){
        if(i>=pairs.size()) return 0;
       // string str=to_string(i)+" "+to_string(prev);
        int ans=0;
        bool flag=true;
        if(prev<0) flag=false;
        int c=prev;
        c=abs(c);
        if(dp[i][c][flag]!=-1) return dp[i][c][flag];
        //if(mp.find(str)!=mp.end()) return mp[str];
        for(int j=i;j<pairs.size();j++){
            if(prev<pairs[j][0]){
                int right=1+rec(j+1,pairs,pairs[j][1]);
                ans=max(ans,right);
            }
        }
        return dp[i][c][flag]=ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
     //   dp=vector<vector<int>>(pairs.size()+1,vector<int>())
        memset(dp,-1,sizeof(dp));
        return rec(0,pairs,-1004);
    }
};