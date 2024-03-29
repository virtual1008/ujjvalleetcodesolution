class Solution 
{
public:
    
    int fn(vector<int> &nums, int l, int r, int total, vector<vector<int>> &dp)
    {
        if(l>=r)            
            return 0;
        if(dp[l][r]!=-1)    
            return dp[l][r];
        
        int sum = 0, ans = INT_MIN;
        for(int i=l;i<=r;i++)
        {
            sum+=nums[i];
            int leftsum = total - sum;
            
            if(sum < leftsum)   
                ans = max(ans,sum + fn(nums,l,i,sum,dp));
            else if(sum > leftsum)  
                ans = max(ans,leftsum + fn(nums,i+1,r,leftsum,dp));
            else                
                ans = max({ans, sum + fn(nums,l,i,sum,dp) , leftsum + fn(nums,i+1,r,leftsum,dp)});
        }
        return dp[l][r] = ans;
    }
    
    int stoneGameV(vector<int>& stoneValue) 
    {
        int l = 0, r = stoneValue.size()-1, total = 0;
        vector<vector<int>> dp(stoneValue.size(), vector<int>(stoneValue.size(),-1));
        for(auto &e: stoneValue)
            total+=e;
        return fn(stoneValue, l, r, total,dp);
        
    }
};