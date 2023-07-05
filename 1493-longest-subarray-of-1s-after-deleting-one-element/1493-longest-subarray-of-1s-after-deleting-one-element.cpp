class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,zero=0;
        int n=nums.size();
        int ans=0;
        while(r<n){
            if(nums[r]==0){
                zero++;
            }
            while(zero>1){
                if(nums[l]==0) zero--;
                l++;
            }
            ans=max(ans,r-l);
            r++;
        }
        return ans;
    }
};