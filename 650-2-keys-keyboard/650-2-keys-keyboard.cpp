class Solution {
public:
    int ans=INT_MAX;
    void rec(int k,int copy,int n,int cnt){
        if(k==n){
            ans=min(ans,cnt);
        }else if(k+copy<=n){
           rec(k+copy,copy,n,cnt+1);
            rec(k+copy,copy+k,n,cnt+2);
        }
        
    }
    int minSteps(int n) {
        if(n==1) return 0;
        rec(1,1,n,1);
        return ans;
    }
};