class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double x=log10(INT_MAX)/log10(3);
        x=(int)x;
        int c=pow(3,x);
        return c%n==0;
    }
};