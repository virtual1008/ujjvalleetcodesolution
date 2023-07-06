class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),-1);
        int i=0;
        long long temp=0;
        int c=2*k+1;
        for(i=0;i<c && i<nums.size();i++){
            temp+=nums[i];
        }
        int cen=k;
        if(cen>=nums.size() || 2*cen>=nums.size()) return ans;
        int j=0;
        ans[cen]=(temp)/c;
        while(i<nums.size()){
            temp-=nums[j];
            temp+=nums[i];
            i++;
            j++;
            cen++;
            ans[cen]=(temp)/c;
        }
         return ans;   
    }
};