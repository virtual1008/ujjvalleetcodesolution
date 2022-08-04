class Solution {
public:
    int mirrorReflection(int p, int q) {
        int gcd=__gcd(p,q);
        p/=gcd,q/=gcd;
        return 1 - p % 2 + q % 2;
    }
};