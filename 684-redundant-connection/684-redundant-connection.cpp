class Solution {
public:
    int findparent(int u,vector<int>& parent){
        if(parent[u]==u) return u;
        return parent[u]=findparent(parent[u],parent);
    }
    void unionval(int u,int v,vector<int> &parent,vector<int> &rank){
       int a=findparent(u,parent);
        int b=findparent(v,parent);
        if(rank[a]>rank[b]){
            parent[b]=a;
        }
        else if(rank[a]<rank[b]){
            parent[a]=b;
        }else{
            parent[b]=a;
            rank[a]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1),rank(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            if(findparent(a,parent)==findparent(b,parent)) return {a,b};
            else unionval(a,b,parent,rank);
        }
        return {-1,-1};
    }
};