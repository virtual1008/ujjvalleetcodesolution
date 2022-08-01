class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        int length=0;
        vector<int> dir ={1,0,-1,0,1};
        while(!q.empty()){
            int siz=q.size();
            length++;
            for(int i=0;i<siz;i++){
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                   int x=it.first+dir[i];
                   int y=it.second+dir[i+1];
                   if(x<0 || x>=n || y<0 || y>=m || mat[x][y]!=-1) continue;
                    mat[x][y]=length;
                    q.push({x,y});
                }
            }
        }
        return mat;
    }
};