class Solution {
public:
    int n,m;
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> result(m);
        vector<vector<int>> memo(n, vector<int>(m, -2));
        for(int i = 0; i < m; i++)
            result[i] = helper(memo, grid, 0, i);
        return result;
    }
    int helper(vector<vector<int>>& memo, vector<vector<int>>& grid, int i, int j){
        if(i == n)
            return j;
        if(memo[i][j] != -2)
            return memo[i][j];
        if(grid[i][j] == 1 && (j == m - 1 || grid[i][j + 1] == -1) || grid[i][j] == -1 && (j == 0 || grid[i][j - 1] == 1))
            return memo[i][j] = -1;
        return memo[i][j] = helper(memo, grid, i + 1, j + grid[i][j]);
    }
};