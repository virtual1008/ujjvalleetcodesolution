class Solution {
public:
    
    int climbStairs(int n) {
        int f=1;
        int s=1;
        for(int i=0;i<n-1;i++){
            int t=f;
            f=f+s;
            s=t;
            
        }
        return f;
    }
};