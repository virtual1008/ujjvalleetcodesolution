class Solution {
public:
    int rec(int i,int sum,int temp,vector<int>& nums){
        if(i<0){
            if(sum==temp) return 1;
            else return 0;
        }
        int take=0,ntake=0;
        if(temp+nums[i]<=sum) take=rec(i-1,sum,temp+nums[i],nums);
        ntake=rec(i-1,sum,temp,nums);
        return take+ntake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums) sum+=it;
        sum+=target;
        if(sum%2!=0) return 0;
        sum/=2;
        return rec(nums.size()-1,sum,0,nums);
    }
};