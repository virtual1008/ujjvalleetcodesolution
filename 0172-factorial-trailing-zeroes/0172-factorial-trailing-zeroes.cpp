class Solution {
public:
    int trailingZeroes(int n) {
        long long five=0;
        long long  two=0;
        for(int i=2;i<=n;i++){
            int k=i;
            while(k%5==0){
                k/=5;
                five++;
            }
            while(k%2==0){
                k/=2;
                two++;
            }
        }
        return min(two,five);
    }
};