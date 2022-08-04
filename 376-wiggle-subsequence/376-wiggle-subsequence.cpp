class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up=1,down=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) up=down+1;
            if(nums[i]<nums[i+1]) down=1+up;
        }
        return max(up,down);
    }
};