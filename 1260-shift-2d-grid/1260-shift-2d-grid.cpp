class Solution {
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> & grid, int k)
    {
        const int m = std::size(grid);
        const int n = std::size(grid[0]);
        k %= m * n;
        
        std::vector<int> temp(m * n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                temp[n * i + j] = grid[i][j];
        
        std::rotate(std::begin(temp), std::end(temp) - k, std::end(temp));
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                grid[i][j] = temp[n * i + j];
        
        return std::move(grid);
    }
};