class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        int k=1;
        while(n>0){
            n-=(2*k+1);
            k++;
        }
        return k-1;
    }
};