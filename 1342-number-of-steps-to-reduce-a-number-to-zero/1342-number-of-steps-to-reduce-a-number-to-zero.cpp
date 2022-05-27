class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return 0;
        int i=1;
        int cnt=0;
        while(num>0){
            if(num&1) cnt+=2;
            else cnt++;
            num=num>>1;
        }
        cnt-=1;
        return cnt;
    }
};