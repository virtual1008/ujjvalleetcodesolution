class Solution {
public:
    int mod=1e9+7;
    vector<int> dp;
    int rec(int n,int zero,int one){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(rec(n-zero,zero,one)%mod+rec(n-one,zero,one)%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
       int ans=0;
       dp=vector<int> (high+1,-1);
       for(int i=low;i<=high;i++){
           ans=(ans%mod+rec(i,zero,one)%mod)%mod;
           ans%=mod;
       }     
       return ans;
    }
};