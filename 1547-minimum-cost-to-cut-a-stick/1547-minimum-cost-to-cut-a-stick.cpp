class Solution {
public:
    vector<vector<int>> dp;
    int rec(int l,int r,int i,int j,vector<int> &cuts){
        if(l>=r || i>j) return 0;
        if(i==j) return r-l;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            ans=min(ans,r-l+rec(l,cuts[k],i,k-1,cuts)+rec(cuts[k],r,k+1,j,cuts));
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        dp=vector<vector<int>>(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        sort(cuts.begin(),cuts.end());
        return rec(0,n,0,cuts.size()-1,cuts);
    }
};