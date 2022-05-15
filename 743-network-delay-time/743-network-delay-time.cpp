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
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int di=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int next=it.first;
                int nextdist=it.second;
                if(dist[next]>dist[node]+nextdist){
                    dist[next]=dist[node]+nextdist;
                    pq.push({dist[next],next});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};