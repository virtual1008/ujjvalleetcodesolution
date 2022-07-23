
class Solution {
public:
      
    int minimumObstacles(vector<vector<int>>& grid) {
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> direction={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=grid[0][0];
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==n-1 && y==m-1) return d;
            for(auto it:direction){
                int dx=it.first;
                int dy=it.second;
                int nx=x+dx;
                int ny=y+dy;
                if(ny>=0 && nx>=0 && nx<n && ny<m &&  dist[nx][ny]>d+grid[x][y]){
                    dist[nx][ny]=d+grid[x][y];
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<"\n";
        }
        return dist[n-1][m-1];
    }
};