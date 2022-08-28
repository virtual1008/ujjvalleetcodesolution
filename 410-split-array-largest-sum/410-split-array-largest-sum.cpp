class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int m,vector<int> &nums){
        if(i==nums.size()) return 0;
        int ans=INT_MAX;
        int sum=0;
        if(dp[i][m]!=-1) return dp[i][m];
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(nums.size()-(j+1)<m-1) break;
            ans=min(ans,max(sum,rec(j+1,m-1,nums)));
        }
        return dp[i][m]=ans;
    }
    int splitArray(vector<int>& nums, int m) {
        dp=vector<vector<int>>(nums.size()+1,vector<int>(m+1,-1));
        return rec(0,m,nums);
    }
};