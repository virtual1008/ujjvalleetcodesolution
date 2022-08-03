class Solution {
public:
    int poorPigs(int buckets, int Die, int Test) {
        return ceil(log(buckets)/(log(Test/Die+1)));
    }
};