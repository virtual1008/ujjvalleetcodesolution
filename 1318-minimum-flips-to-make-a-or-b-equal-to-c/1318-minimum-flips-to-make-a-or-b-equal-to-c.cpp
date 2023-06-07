class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<31;i++){
            int b1=a&(1<<i);
            int b2=b&(1<<i);
            int b3=c&(1<<i);
            if(b3){
                if(b1||b2) continue;
                else ans++;
            }else{
                if(b1&b2) ans+=2;
                else if(b1|| b2) ans++;
                else continue;
            }
        }
        return ans;
    }
};