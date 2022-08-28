class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int m,vector<int> &nums){
        if(i>=nums.size()) return 0;
        int sum=0;
        int ans=INT_MAX;
        if(dp[i][m]!=-1) return dp[i][m];
        for(int j=i;j<nums.size();j++){
            if(nums.size()-(j+1)<m-1) break;
            sum+=nums[j];
            ans=min(ans,max(sum,rec(j+1,m-1,nums)));
        }
        return dp[i][m]=ans;
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return rec(0,m,nums);
    }
};