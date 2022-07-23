class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
       // vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<vector<int>> q;
        //return 6;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        q.push({0,0,0,k});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it[0];
            int y=it[1];
            int len=it[2];
            int cnt=it[3];
            if(x<0 ||y<0 || x>=n || y>=m) continue;
            if(x==n-1 && y==m-1) return len;
            if(grid[x][y]==1){
                if(cnt>0){
                    cnt--;
                }else continue;
            }
            if(vis[x][y]<cnt){
                vis[x][y]=cnt;
                q.push({x-1,y,len+1,cnt});
                q.push({x+1,y,len+1,cnt});
                q.push({x,y-1,len+1,cnt});
                q.push({x,y+1,len+1,cnt});
                
                
                
                
            }
            
        }
        return -1;
    }
};