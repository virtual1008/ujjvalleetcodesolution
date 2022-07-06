class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        int maxi=0;
        int index=0;
        vector<int> ans;
        vector<int> hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1){
                    hash[i]=prev;
                    dp[i]=dp[prev]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                index=i;
            }
        }
        ans.push_back(nums[index]);
        while(hash[index]!=index){
            index=hash[index];
            ans.push_back(nums[index]);
            
        }
        return ans;
    }
};