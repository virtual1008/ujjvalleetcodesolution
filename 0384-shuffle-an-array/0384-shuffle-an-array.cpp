class Solution {
public:
    vector<int> v1,v2;
    Solution(vector<int>& nums) {
        v1=v2=nums;
    }
    
    vector<int> reset() {
        return v2;
    }
    
    vector<int> shuffle() {
        int p1=(rand())%v1.size();
        int p2=(rand())%v1.size();
        swap(v1[p1],v1[p2]);
        return v1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */