class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        int i=1;
        while(i*i <= 1e4)
        {
            squares.push_back(i*i);
            i++;
        }
        int s = squares.size();
        vector<vector<int>> dp(s+1,vector<int>(n+1,-1));
        return solve(squares,s,n,dp);
    }
    
    int solve(vector<int>& squares, int n, int sum, vector<vector<int>>& dp)
    {
        if(sum==0)
            return 0;
        if(n==0)
            return 1e9;
        
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        int pick = 1e9;
        
        if(squares[n-1] <= sum)
            pick = 1 + solve(squares,n,sum-squares[n-1],dp); 
        int notpick = solve(squares,n-1,sum,dp);
        
        return dp[n][sum] = min(pick,notpick);
    }
};