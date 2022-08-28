class Solution {
public:
    int rec(int k,int copy,int cnt,int n){
        if(n==k) return cnt;
        if(n<k) return 1e6;
        return min(rec(k+copy,copy,cnt+1,n),rec(k+copy,copy+k,cnt+2,n));
    }
    int minSteps(int n) {
        if(n==1) return 0;
        return rec(1,1,1,n);
    }
};