class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i>=nums1.size() || j>=nums2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]) return dp[i][j]=1+rec(i+1,j+1,nums1,nums2);
        return dp[i][j]=max(rec(i+1,j,nums1,nums2),rec(i,j+1,nums1,nums2));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp=vector<vector<int>>(nums1.size(),vector<int>(nums2.size(),-1));
        return rec(0,0,nums1,nums2);
    }
};