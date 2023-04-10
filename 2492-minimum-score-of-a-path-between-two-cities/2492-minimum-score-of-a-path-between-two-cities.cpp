class Solution {
public:
    // we know that there is atleast one path from 1 to n so our task is to find all the nodes which is the part of the 1 to n component
    void dfs(int node ,vector<int> & vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,adj);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> exist(n+1,0);
        vector<int> adj[n+1];
        map<pair<int,int>,int> mp;
        for(auto it:roads){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(a>b) swap(a,b);
            if(mp[{a,b}]){
                mp[{a,b}]=min(mp[{a,b}],c);
            }else{
                mp[{a,b}]=c;
            }
        }
        dfs(1,exist,adj);
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            for(auto it:adj[i]){
                int a=i;
                int b=it;
                if(exist[a] && exist[b]){
                    if(a>b) swap(a,b);
                ans=min(ans,mp[{a,b}]);
                }
            }
        }
        return ans;
    }
};