class Solution {
public:
    vector<int> dp;
    int rec(int s, int  mask, vector<int> & nums1 ,vector<int> & nums2){
        if(s>=nums2.size()) return 0;
        if(dp[mask]==INT_MAX){
            for(int j=0;j<nums1.size();j++){
                if((mask &(1<<j))==0){
                    dp[mask]=min(dp[mask],(nums1[s]^nums2[j])+rec(s+1,mask+(1<<j),nums1,nums2));
                }
            }
        }
        return dp[mask];
        
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        dp=vector<int>(1<<14,INT_MAX);
        int mask=0;
        return rec(0,mask,nums1,nums2);
    }
};