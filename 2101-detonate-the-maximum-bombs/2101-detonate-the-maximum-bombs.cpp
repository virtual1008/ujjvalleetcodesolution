class Solution {
public:
    void rec(int i,vector<int> adj[],vector<int> &vis,int &cnt){
        vis[i]=true;
        cnt++;
        for(auto it:adj[i]){
            if(!vis[it]){
                rec(it,adj,vis,cnt);
            }
        }
        return ;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> adj[n];
        for(int i=0;i<bombs.size();i++){
            long long x1=bombs[i][0];
            long long y1=bombs[i][1];
            long long r1=bombs[i][2];
            for(int j=0;j<bombs.size();j++){
                if(i==j) continue;
                long long x2=bombs[j][0];
                long long y2=bombs[j][1];
                long long r2=bombs[j][2];
                long long dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                if(r1*r1>=dist){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            int cnt=0;
            rec(i,adj,vis,cnt);
            ans=max(ans,cnt);
        }
        return ans;
        
    }
};