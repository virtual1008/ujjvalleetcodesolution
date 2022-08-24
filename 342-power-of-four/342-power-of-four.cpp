class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        double x=log10(n)/log10(2);
        if(x==(int)x) return (int)x%2==0;
        return false;
    }
};