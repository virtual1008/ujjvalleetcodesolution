class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      int a=left;
      int b=right;
      //first find no of bits present in both number 
       int cnt1=0;
        int cnt2=0;
        while(a>0){
            a/=2;
            cnt1++;
        }
        while(b>0){
            b/=2;
            cnt2++;
        }
        if(abs(cnt1-cnt2)) return 0;
        long long res=left;
        for(long long i=left;i<=right;i++){
            res&=i;
            
        }
        return res ;
        
    }
};