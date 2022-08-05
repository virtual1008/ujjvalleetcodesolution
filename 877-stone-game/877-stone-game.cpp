class Solution {
public:
    int dp[502][502][2];
    int rec(int l,int r,int k,vector<int> prices){
        if(l>r) return 0;
        if(dp[l][r][k]!=-1) return dp[l][r][k];
        if(k){
            return dp[l][r][k]=max(prices[l]+rec(l+1,r,1-k,prices),prices[r]+rec(l,r-1,1-k,prices));
        }else{
            return dp[l][r][k]=min(rec(l+1,r,1-k,prices),rec(l,r-1,1-k,prices));
        }
    }
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        for(auto it:piles) sum+=it;
        memset(dp,-1,sizeof(dp));
        return 2*(sum-rec(0,piles.size()-1,1,piles))<sum; 
    }
};