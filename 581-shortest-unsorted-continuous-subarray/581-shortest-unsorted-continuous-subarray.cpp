class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ans=nums;
        sort(ans.begin(),ans.end());
        if(ans==nums) return 0;
        int l=0,r=nums.size()-1;
        int pre=0,cnt=0;
        while(l<r){
            if(nums[l]==ans[l]){
                l++;
                cnt++;
            }
            if(nums[r]==ans[r]) {
                r--;
                cnt++;
            }
            if(cnt==pre) break;
            pre=cnt;
            
        }
        return(r-l+1);
    }
};