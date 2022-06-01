class Solution {
public:
    map<int,vector<pair<int,int>>> row,column;
    map<pair<int,int>,int> vis;
    void dfs(int r,int c){
        vis[{r,c}]=1;
        for(auto it:row[r]){
            int a=it.first;
            int b=it.second;
            if(vis[{a,b}]==0) dfs(a,b);
        }
        for(auto it:column[c]){
            int a=it.first;
            int b=it.second;
            if(vis[{a,b}]==0) dfs(a,b);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        for(auto it:stones){
            int r=it[0];
            int c=it[1];
            row[r].push_back({r,c});
            column[c].push_back({r,c});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int r=stones[i][0];
            int c=stones[i][1];
            if(vis[{r,c}]==0){
                ans++;
                dfs(r,c);
            }
         }
        return n-ans;
    }
};