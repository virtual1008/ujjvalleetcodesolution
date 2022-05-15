class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            adj[a].push_back({b,c});
        }
        vector<int> ti(n+1,INT_MAX);
        ti[0]=0;
        ti[k]=0;
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                int a=it.first;
                int b=it.second;
                if(ti[a]>ti[node]+b){
                    ti[a]=ti[node]+b;
                    q.push(a);
                }
            }
        }
        int maxi=INT_MIN;
        for(auto it:ti) maxi=max(maxi,it);
        if(maxi==INT_MAX) return -1;
        return maxi;
        
    }
};