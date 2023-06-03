class Solution {
public:
    int rec(int node,int parent,vector<int> adj[],vector<int>& informTime,vector<int> & manage){
        int ans=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            ans=max(ans,rec(it,node,adj,informTime,manage));
        }
        ans+=informTime[node];
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        return rec(headID,-1,adj,informTime,manager);
    }
};