class Solution {
public:
    int dp[22][22]; 
    int rec(int i,int j,int k,vector<int> & nums ){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(k){
            return dp[i][j]=max(nums[i]+rec(i+1,j,1-k,nums),nums[j]+rec(i,j-1,1-k,nums));
        }else{
            return dp[i][j]=min(rec(i+1,j,1-k,nums),rec(i,j-1,1-k,nums));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        memset(dp , -1, sizeof(dp));
        return sum<=2*rec(0,nums.size()-1,1,nums);
    }
};