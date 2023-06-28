class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> temp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                temp.push_back({i,j});
            }
        }
        int n=matrix.size();
        int m=matrix[0].size();
        for(auto it:temp){
            int a=it.first;
            int b=it.second;
            int c=0;
            while(c<n){
                matrix[c][b]=0;
                c++;
            }
            c=0;
            while(c<m){
                matrix[a][c]=0;
                c++;
            }
        }
    }
};