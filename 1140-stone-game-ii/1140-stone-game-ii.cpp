class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int m,vector<int> p){
        if(i>=p.size()) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int mini=INT_MIN;
         int ans=0;
            for(int j=0;j<2*m;j++){
                if(i+j<p.size()) ans+=p[i+j];
                mini=max(mini,ans-rec(i+j+1,max(m,j+1),p));
            }
        return dp[i][m]=mini;
    }
    int stoneGameII(vector<int>& p) {
        int sum=0;
        dp=vector<vector<int>>(p.size()+1,vector<int>(p.size()+1,-1));
        for(auto it:p) sum+=it;
        return (sum+rec(0,1,p))/2;
    }
};