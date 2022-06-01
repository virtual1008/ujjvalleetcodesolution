class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
       int n=graph.size();
       int allvis=(1<<n)-1;
        int ans=-1;
        queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>> st;
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({i,{0,mask}});
            st.insert({i,mask});
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int dist=it.second.first;
            int mask=it.second.second;
            if(mask==allvis){
                ans=dist;
                break;
            }
            for(auto ele:graph[node]){
                int newmask=(mask|(1<<ele));
                if(st.count({ele,mask})) continue;
                else{
                    q.push({ele,{dist+1,newmask}});
                    st.insert({ele,mask});
                }
            }
        }
        return ans;
        
    }
};