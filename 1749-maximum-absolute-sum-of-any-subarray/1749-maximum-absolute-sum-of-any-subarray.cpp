class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr1=0;
        int ans=INT_MIN;
        int curr2=0;
        for(int i=0;i<nums.size();i++){
            curr1=max(curr1+nums[i],nums[i]);
            curr2=min(curr2+nums[i],nums[i]);
            int a=curr1;
            int b=curr2;
            ans=max(ans,abs(a));
            ans=max(ans,abs(b));
        }
        return ans;
    }
};