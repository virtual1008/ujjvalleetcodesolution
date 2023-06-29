class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]>nums[i]) swap(nums[j],nums[i]);
            }
        }
    }
};