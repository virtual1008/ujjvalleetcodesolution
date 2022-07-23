class Solution {
public:
    vector <int> adj[30000];
    int count[30000];
    int sum[30000];
    
    void postorder(int node, int par){
        for(auto i:adj[node]){
            if(i!=par){
                postorder(i,node);
                count[node]+= count[i];
                sum[node] += sum[i] + count[i]; 
            } 
        }
        count[node]+=1;
        
    }
    
    void preorder(int node, int par, int n){
        if(par!=-1)sum[node]+= (sum[par]-sum[node]-count[node]+n-count[node]);
        for(auto i:adj[node]){
            if(i!=par)preorder(i,node,n);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector <int> ret;
        memset(count,0,sizeof count);
        memset(sum,0,sizeof sum);
        postorder(0,-1);
        preorder(0,-1, n);
        for(int i=0;i<n;i++) ret.push_back(sum[i]);
        return ret;
    }
};