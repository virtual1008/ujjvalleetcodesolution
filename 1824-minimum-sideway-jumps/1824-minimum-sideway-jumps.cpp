class Solution {
public:
    int dp[500001][3];
    int minSideJumps(vector<int>& obstacles) {
        memset(dp, -1, sizeof(dp));
        return rec(obstacles, 0, 1);
    }
    int rec(vector<int>& obstacles, int i, int j){
        if(j<0||j>2||obstacles[i]-1==j)
            return INT_MAX;
        if(i>=obstacles.size()-1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(obstacles[i+1]-1!=j)
            return dp[i][j]=rec(obstacles, i+1, j);
        return dp[i][j]=1+min(rec(obstacles, i, j+1), min(rec(obstacles, i, j+2), min(rec(obstacles, i, j-1), rec(obstacles, i, j-2))));
    }
};