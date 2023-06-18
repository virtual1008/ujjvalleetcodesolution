class Solution {
public:
    vector<int> dir={0,1,0,-1,0};
    vector<vector<int>> dp;
    int rec(int i,int j,vector<vector<int>> & matrix){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()) return 0;
        int len=0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<4;k++){
            int x=i+dir[k];
            int y=j+dir[k+1];
            if(x<0 || y<0 || x>=matrix.size() || y>=matrix[0].size()) continue;
            if(matrix[i][j]<matrix[x][y]){
                len=max(len,1+rec(x,y,matrix));
            }
        }
        return dp[i][j]=len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        dp=vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,1+rec(i,j,matrix));
            }
        }
        return ans;
    }
};