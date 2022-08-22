class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k%2 && nums.size()==1) return -1;
        else if(k%2==0 && nums.size()==1) return nums[0];
        
        
        if(k<2)
            return nums[k];
        
        if(k>nums.size())
        {
            return *max_element(nums.begin(),nums.end());
        }
        else if(k==nums.size())
        {
            return *max_element(nums.begin(),nums.begin()+nums.size()-1);
        }
        else
        {
             return max(nums[k], *max_element(begin(nums), begin(nums) + k - 1));
        }
    }
};