class Solution {
public:
    void dfs(int &cnt, int i,int j,vector<vector<int>> &v){
        int n=v.size();
        int m=v[0].size();
       if(i<0||j<0||i>(n-1)||j>(m-1)||v[i][j]!=1)
        {
            return;
        }
        v[i][j]=0;
        cnt++;
        dfs(cnt,i,j+1,v);
        dfs(cnt,i+1,j,v);
        dfs(cnt,i-1,j,v);
        dfs(cnt,i,j-1,v);
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
         
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            //cnt=0;
            for(int j=0;j<m;j++){
                cnt=0;
               if(v[i][j]==1){
                  cnt++;
                   v[i][j]=0;
                   dfs(cnt,i,j+1,v);
                   dfs(cnt,i+1,j,v);
                   dfs(cnt,i-1,j,v);
                   dfs(cnt,i,j-1,v);  
               }
                ans=max(ans,cnt);
            }
           
        }
        return ans;
    }
};