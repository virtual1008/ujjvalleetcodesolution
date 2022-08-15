class Solution {
public:
    vector<vector<vector<int>>> dp;
    int rec(int l,int r,int k,vector<int> p){
        if(l>r) return 0;
        if(dp[l][r][k]!=-1) return dp[l][r][k];
        if(k){
            return dp[l][r][k]=max(p[l]+rec(l+1,r,1-k,p),p[r]+rec(l,r-1,1-k,p));
        }else{
            return dp[l][r][k]=max(-p[l]+rec(l+1,r,1-k,p),-p[r]+rec(l,r-1,1-k,p));
        }
    }
    bool stoneGame(vector<int>& p) {
        dp= vector<vector<vector<int>>>(p.size(), vector<vector<int>>(p.size(),vector<int>(2,-1)));
        int c=rec(0,p.size()-1,1,p);
        cout<<c;
        cout<<"\n";
        return c>0?"Alice":"Bob";
    }
}; 