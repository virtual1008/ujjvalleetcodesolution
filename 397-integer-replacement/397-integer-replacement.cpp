class Solution {
public:
    long long c;
    long long rec(long long n){
      if( n> 2*c || n==0) return 1e6;
      if(n==1) return 0;
      if(n%2==0){
         return 1+rec(n/2);
      }else{
          return 1+min(rec(n-1),rec(n+1));
      }  
    }
    int integerReplacement(int n) {
        c=(long long)n;
        return (int)rec(n);
    }
};