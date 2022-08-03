class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int x=9,y=9,ans=1;
        for(int i=0;i<n;i++){
            ans+=x;
            x*=(y-i);
        }
        return ans;
    }
};