class Solution {
public:
    int getSum(int a, int b) {
        unsigned carry;
        while(b){
            carry=a&b;
            a^=b;
            b=carry<<1;
            cout<<carry<<" "<<a<<" "<<b<<"\n";
        }
        return a;
    }
};