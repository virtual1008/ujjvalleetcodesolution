class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> temp;
        for(auto it:nums1) temp[it]++;
        vector<int> ans;
        for(auto it:nums2){
            if(temp[it]>0){
                ans.push_back(it);
                temp[it]--;
            }
        }
        return ans;
    }
};