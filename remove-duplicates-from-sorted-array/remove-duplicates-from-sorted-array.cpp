class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto it:nums) st.insert(it);
        vector<int> temp;
        for(auto it:st) temp.push_back(it);
        nums=temp;
        return nums.size();
    }
};