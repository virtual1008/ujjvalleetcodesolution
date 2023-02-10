class Solution {
public:
    int maxDistance(vector<vector<int>> grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        int k=grid.size();
        if( q.size()==k*k) return -1;
        int ans=-1;
        vector<int> dist={1,0,-1,0,1};
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                for(int j=0;j<4;j++){
                   int temp1=x+dist[j];
                   int temp2=y+dist[j+1];
                   if(temp1>=0 && temp2>=0 && temp1<grid.size() && temp2<grid.size() && grid[temp1][temp2]==0){
                      grid[temp1][temp2]=1;
                      q.push({temp1,temp2});
                   }
                }
                
            }
            ans++;
        }
        return ans;
    }
};