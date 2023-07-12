class Solution {
public:
    void rec(int node,vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis){
        vis[node]=dfsvis[node]=true;
        for(auto it:adj[node]){
            if(vis[it]==false) rec(it,adj,vis,dfsvis);
            if(dfsvis[it]) return ;
        }
        dfsvis[node]=false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> adj[n];
        int i=0;
        for(auto it:graph){
            for(auto e:it){
                adj[i].push_back(e);
            }
            i++;
        }
        vector<bool> dfs(n,false),vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                rec(i,adj,vis,dfs);
            }
        }
        for(int i=0;i<n;i++){
            if(dfs[i]==0)ans.push_back(i);
        }
        return ans;
    }
};