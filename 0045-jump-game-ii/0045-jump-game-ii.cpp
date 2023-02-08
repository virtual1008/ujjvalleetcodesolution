class Solution {
public:
    vector<int> dp;
    int rec(int i,vector<int> & nums){
        if(i>=nums.size()-1) return 0;
        int ans=1e6;
        if(dp[i]!=-1) return dp[i];
        if(nums[i]!=0){
            for(int j=1;j<=nums[i];j++){
               ans=min(ans,1+rec(i+j,nums));
            }
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        dp=vector<int> (2*nums.size()+1,-1);
        return rec(0,nums);
    }
};