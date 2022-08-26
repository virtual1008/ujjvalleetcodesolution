class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            int val=nums[i-1]*nums[j+1]*nums[k]+rec(i,k-1,nums)+rec(k+1,j,nums);
            ans=max(ans,val);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        dp=vector<vector<int>>(n+2,vector<int>(n+2,-1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return rec(1,n,nums);
    }
};