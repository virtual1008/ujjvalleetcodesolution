class Solution {
public:
    vector<int> dist;
    int ans=-1;
    void dfs(int node ,vector<int> adj[],vector<int> &vis,vector<int> &visdfs){
        vis[node]=1;
        visdfs[node]=1;
        for(auto it:adj[node]){
            if(vis[it]!=1){
                dist[it]=1+dist[node];
                dfs(it,adj,vis,visdfs);
            }else if(visdfs[it]==1){
                ans=max(ans,abs(dist[it]-dist[node])+1);
            }
        }
        visdfs[node]=0;
        return;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1) adj[i].push_back(edges[i]);
        }
        vector<int> vis(n,0),visdfs(n,0);
        dist=vector<int>(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                dfs(i,adj,vis,visdfs);
            }
        }
        return ans;
    }
};