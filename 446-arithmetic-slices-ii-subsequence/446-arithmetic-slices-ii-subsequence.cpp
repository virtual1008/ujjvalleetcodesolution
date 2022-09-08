class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       int ans=0;
       vector<unordered_map<long long ,long long>> mp(nums.size());
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long long d=(long long)nums[i];
                d-=(long long)nums[j];
                ans+=mp[j][d];
                mp[i][d]=mp[j][d]+mp[i][d]+1;
            }
        }
        return ans;
    }
};