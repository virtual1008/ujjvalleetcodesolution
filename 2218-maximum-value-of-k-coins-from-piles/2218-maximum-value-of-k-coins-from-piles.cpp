class Solution {
public:
    vector<vector<int>> dp;
    int rec(int ind,int k,vector<vector<int>> & piles){
        if(k==0) return 0;
        if(ind==piles.size()){
            if(k==0) return 0;
            return -1e6;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        int ans=-1e6;
        for(int i=0;i<min(k,(int)(piles[ind].size()));i++){
             ans=max(ans,piles[ind][i]+rec(ind+1,k-(i+1),piles));
        }
        return dp[ind][k]=max(ans,rec(ind+1,k,piles));
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        dp=vector<vector<int>>(n+1,vector<int>(k+1,-1));
        for (int i = 0; i < n; i++)
            for (int j = 1; j < piles[i].size(); j++)
                piles[i][j] += piles[i][j - 1];
        
        return rec(0,k,piles);
        
    }
};