class Solution {
public:
    
    int nthUglyNumber(int n) {
      set<long long> a,b;
        a.insert(1);
        while((int)b.size()!=n){
            long long c=*a.begin();
            b.insert(c);
            a.erase(c);
            a.insert(2*c);
            a.insert(3*c);
            a.insert(5*c);
            
        }
        return *(b.rbegin());
    }
};