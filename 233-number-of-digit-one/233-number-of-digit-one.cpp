class Solution {
public:
    int rec(int n){
        if(n==0) return 0;
        if(n<10) return 1;
        int s=to_string(n).size();
        int num=pow(10,s-1);
        int a=n/num;
        int ans=a*rec(num-1)+rec(n%num);
        if(a>1) ans+=num;
        else ans+=(n%num)+1;
        return ans;
        
    }
    int countDigitOne(int n) {
        return rec(n);
    }
};