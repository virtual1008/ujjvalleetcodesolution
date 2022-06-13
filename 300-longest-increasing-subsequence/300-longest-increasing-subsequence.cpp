class Solution {
public:
    int recur(int i,int prev_ind,vector<int>& nums,vector<vector<int>>&dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev_ind+1]!=-1) return dp[i][prev_ind+1];
       
       int len=0+recur(i+1,prev_ind,nums,dp);
        
        if(prev_ind==-1 || nums[i]>nums[prev_ind]){
            len=max(len,1+recur(i+1,i,nums,dp));
        }
        return dp[i][prev_ind+1]= len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return recur(0,-1,nums,dp);
    }
};