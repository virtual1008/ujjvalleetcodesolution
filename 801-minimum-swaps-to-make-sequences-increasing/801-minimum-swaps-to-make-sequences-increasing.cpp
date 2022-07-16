class Solution {
public:
    int rec(int i,vector<int> &nums1,vector<int> &nums2,bool val,int maxi1,int maxi2,vector<vector<int>> &dp){
        if(i>=nums1.size()) return 0;
        if(dp[i][val]!=-1) return dp[i][val];
        if(nums1[i]<=maxi1 || nums2[i]<=maxi2) return dp[i][val]=1+rec(i+1,nums1,nums2,true,nums2[i],nums1[i],dp);
        int swap=(maxi1<nums2[i] && maxi2<nums1[i])? 1+rec(i+1,nums1,nums2,true,nums2[i],nums1[i],dp):1e6;
        int nswap=rec(i+1,nums1,nums2,false,nums1[i],nums2[i],dp);
        return dp[i][val]=min(swap,nswap);
        
    }
    int minSwap(vector<int>& v1, vector<int>& v2) {
        int n=v1.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return min(1+rec(0,v1,v2,true,INT_MIN,INT_MIN,dp),rec(0,v1,v2,false,INT_MIN,INT_MIN,dp));
    }
};