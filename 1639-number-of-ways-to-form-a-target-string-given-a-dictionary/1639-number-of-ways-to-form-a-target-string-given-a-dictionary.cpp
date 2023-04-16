class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> dp;
    int rec(int i ,int j,vector<string> & words,string &target){
        if(i==target.size()) return 1;
        if(j==words[0].size() || (target.size()-i)>words[0].size()-j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int not_take=rec(i,j+1,words,target);
        int take=0;
        for(int k=0;k<words.size();k++){
            if(words[k][j]==target[i]) take=(take%mod+rec(i+1,j+1,words,target)%mod)%mod;
        }
        return dp[i][j]=((take)%mod+(not_take)%mod)%mod;
    }
    int numWays(vector<string>& words, string target) {
        dp=vector<vector<int>>(target.size(),vector<int>(words[0].size(),-1));
        return rec(0,0,words,target);
    }
};