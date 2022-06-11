class KthLargest { 
public:
    multiset<int> s;
    int k;
    KthLargest(int k, vector<int>& nums) 
        : s(nums.begin(), nums.end()) //T: O(N * logN)= O(nlogn)
        , k(k) 
    {
        while(s.size() > k) s.erase(s.begin());
    }
    
    int add(int val) { //M times
        s.insert(val); //O(logk)
        if (s.size() > k) {
            s.erase(s.begin());  //O(logk)
        }
        return *(s.begin());
    }
};
