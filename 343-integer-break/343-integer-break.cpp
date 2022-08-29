class Solution {
public:
    int v[60];
    int rec(int n){
        if(n==1) return n;
        if(v[n]!=-1) return v[n];
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            int cnt=max(i*rec(n-i),i*(n-i));
            ans=max(ans,cnt);
        }
        return v[n]=ans;
    }
    int integerBreak(int n) {
        memset(v,-1,sizeof(v));
        return rec(n);
    }
};