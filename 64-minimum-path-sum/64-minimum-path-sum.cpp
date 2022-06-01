class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j) {
                if(i-1<0 && j-1<0)
                    continue;
                grid[i][j] += min((i-1)<0? INT_MAX : grid[i-1][j], (j-1)<0? INT_MAX : grid[i][j-1]);
            }
        return grid[m-1][n-1];
    }
};