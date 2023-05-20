class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int val=0;
        // element with self (a|a)&a=a;
        //but other numbers are get repeate combinations
        /*
        like (a|b)&c
        but also exist in array another combination (b|a)&c and both values are same 
        so there xor get 0
        so ultimately only number exist in arry are possible so find there xor directly
        but there is interesting case with array of lenth 1
        let number exist is a
        so 
        ((a|a)&a)^((a|a)&a)=0;
        so answer will be zero
        */
        //if(nums.size()==1) return 0;
        for(auto it:nums) val^=it;
        return val;
    }
};