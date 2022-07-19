class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int left=v[i]*(j+1)+dp[i+1][j+1];
                int right=dp[i+1][j];
                dp[i][j]=max(left,right);
            }
        }
        return dp[0][0];
    }
};