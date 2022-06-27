class Solution {
public:
    int sum;
    long long getans(vector<int>& nums,int index,int sumg,vector<vector<int>>&dp)
    {
        if(index==-1)
            return 0;
        if(sum==sumg)
            return 1;
            if(dp[index][sumg]!=-1)
                return dp[index][sumg];
        return dp[index][sumg]=(getans(nums,index-1,sumg+nums[index],dp)+getans(nums,index-1,sumg,dp));
    }
    bool canPartition(vector<int>& nums) {
        sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        vector<vector<int>>dp(nums.size(),vector<int>(sum,-1));
        if(sum%2==0)
        {
            sum/=2;
            long long k=getans(nums,nums.size()-1,0,dp);
            if(k)
                return true;
            return false;
        }
        return false;
    }
};