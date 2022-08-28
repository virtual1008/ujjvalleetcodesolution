class Solution {
public:
    vector<vector<double>> dp;
    double rec(int i,vector<int> &nums,int k){
        if(i>=nums.size()) return 0;
        if(k<=0) return -1e6;
        if(dp[i][k]!=-1) return dp[i][k];
        double ans=INT_MIN;
        double sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            ans=max(ans,sum/(j-i+1)+rec(j+1,nums,k-1));
        }
        return dp[i][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        dp=vector<vector<double>>(nums.size()+1,vector<double>(k+1,-1));
        return rec(0,nums,k);
    }
};