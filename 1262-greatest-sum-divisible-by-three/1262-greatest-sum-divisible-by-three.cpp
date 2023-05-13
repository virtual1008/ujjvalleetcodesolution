class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int mod,vector<int> &nums){
        if(i==nums.size()){
            if(mod==0) return 0;
            return -1e7;
        }
        if(dp[i][mod]!=-1) return dp[i][mod];
        int pick=nums[i]+rec(i+1,(mod+nums[i])%3,nums);
        int notpick=rec(i+1,mod,nums);
        return dp[i][mod]=max(pick,notpick);
    }
    int maxSumDivThree(vector<int>& nums) {
        dp=vector<vector<int>>(nums.size(),vector<int>(3,-1));
        return rec(0,0,nums);
    }
};