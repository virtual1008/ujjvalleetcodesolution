class Solution {
public:
    // by union find
    vector<int> parent,rank;
    int find(int a){
        if(a==parent[a]) return a;
        return parent[a]=find(parent[a]);
    }
    void dsu(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        else{
            if(rank[a]>=rank[b]){
                parent[b]=a;
            }else{
                parent[a]=b;
            }
            if(rank[a]==rank[b]) rank[a]++;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent=vector<int>(n+1,0);
        rank=vector<int>(n+1,0);
        for(int i=1;i<=n;i++) parent[i]=i;
        for(auto it:roads){
            int a=it[0];
            int b=it[1];
            dsu(a,b);
        }
        int ans=INT_MAX;
        for(auto it:roads){
            int a=it[0];
            int b=it[1];
            int d=it[2];
            int p=find(1);
            a=find(a);
            b=find(b);
            if(a==p && b==p){
                ans=min(ans,d);
            }
        }
        return ans;
    }
};