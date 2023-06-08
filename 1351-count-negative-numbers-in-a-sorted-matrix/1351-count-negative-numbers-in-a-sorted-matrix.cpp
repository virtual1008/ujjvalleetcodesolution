class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        int row=n;
        int col=0;
        int ans=0;
        while(row>=0 && col<=m){
            if(grid[row][col]<0){
                ans+=(m+1-col);
                row--;
            }else{
                col++;
            }
        }
        return ans;
    }
};