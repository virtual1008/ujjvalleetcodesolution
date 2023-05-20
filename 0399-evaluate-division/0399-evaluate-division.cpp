class Solution {
public:
    void dfs(map<string,vector<string>> &graph,double & val,string  u,string  v,map<string,double> & result,bool & flag,map<string,bool> &vis){
        vis[u]=1;
        if(flag) return ;
        for(auto it:graph[u]){
            if(!vis[it]){
                val*=result[u+"->"+it];
                if(it==v){
                   flag=true;
                    return ;
                }else{
                    dfs(graph,val,it,v,result,flag,vis);
                    if(flag){
                        return ;
                    }else{
                        val/=result[u+"->"+it];
                    }
                }
            }
        }
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<string>> graph;
        map<string,double> result;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            result[u+"->"+v]=values[i];
            result[v+"->"+u]=(1.0/values[i]);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<double> ans;
        for(auto it:queries){
            string u=it[0];
            string v=it[1];
            if(graph.find(u)==graph.end() || graph.find(v)==graph.end()){
                ans.push_back(-1);
                continue;
            }
            if(u==v){
                ans.push_back(1);
                continue;
            }
            double val=1;
            bool flag=false;
            map<string,bool> vis;
            dfs(graph,val,u,v,result,flag,vis);
            if(flag){
                ans.push_back(val);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};