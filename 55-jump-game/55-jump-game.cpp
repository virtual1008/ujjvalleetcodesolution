class Solution {
public:
    bool canJump(vector<int>& nums) {
        int siz=nums.size();
        int last=siz-1;
        for(int i=siz-1;i>=0;i--){
            if(nums[i]>=(last-i)){
                last=i;
            }
        }
        if(last==0){
            return 1;
        }
        else{
            return false;
        }
    }
};