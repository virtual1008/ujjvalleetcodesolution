class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,bool flag ,vector<int>& nums){
        if(i>=nums.size()) return 0;
        int l=0,r=0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        if(flag){
            l=rec(i+1,!flag,nums);
        }else{
            r=max(nums[i]+rec(i+1,!flag,nums),rec(i+1,flag,nums));
        }
        return dp[i][flag]=max(l,r);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp=vector<vector<int>>(n,vector<int>(2,-1));
        return rec(0,false,nums);
    }
};