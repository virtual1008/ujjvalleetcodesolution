int dp[1001][1001] = {}, mod = 1000000007;
class Solution {
public:
    //int mod=1e9+7;
    //vector<vector<int>> dp;
    int rec(int k,int d){
        if(d>=k) return d==k;
        if(dp[k][d]==0){
            dp[k][d]=(1+rec(k-1,d+1)%mod+rec(k-1,abs(d-1)%mod))%mod;
        }
        return dp[k][d]-1;
    }
    int numberOfWays(int s, int e, int k) {
        return rec(k,abs(s-e));
    }
};