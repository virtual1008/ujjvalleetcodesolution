class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1)
            return n;
        
        vector<int> Fib(n+1);
        Fib[0] = 0;
        Fib[1] = 1;
        Fib[2] = 1;
        
        for(int i=3;i<=n;i++)
        {
            Fib[i] = Fib[i-1] + Fib[i-2] + Fib[i-3];
        }
        return Fib[n];

    }
};