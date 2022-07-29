class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        map<string,vector<string>> adj;
        map<string,int> degree;
        set<string> st;
        for(auto it:supplies) st.insert(it);
        for(auto it:recipes) degree[it]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<ingredients[i].size();j++){
                string u = recipes[i], v = ingredients[i][j];
                if(st.find(v)==st.end()){
                    adj[v].push_back(u);
                    degree[u]++;
                }
            }
        }
        queue<string> q;
        for(auto& i:recipes)
        {
            if(degree[i]==0)
                q.push(i);
        }
        vector<string> ans;
        while(q.empty()==false){
            string u=q.front();
            q.pop();
            ans.push_back(u);
            for(auto it:adj[u]){
                degree[it]--;
                if(degree[it]==0) q.push(it);
            }
        }
        return ans;
        
    }
};