class Solution {
public:
    vector<int> parent;
    int findpar(int v){
        return parent[v]==v?v:findpar(parent[v]);
    }
    void unionval(int v,int u){
        v=findpar(v);
        u=findpar(u);
        if(v!=u) parent[v]=u;
        return;
    }
    bool equationsPossible(vector<string>& eqs) {
        for(int i=0;i<26;i++)parent.push_back(i);
        for(auto it:eqs){
            int a=it[0]-'a';
            int b=it[1];
            int c=it[3]-'a';
            if(b=='=') unionval(a,c);
        }
        for(auto it:eqs){
            int a=it[0]-'a';
            int b=it[1];
            int c=it[3]-'a';
            if(b=='!' && findpar(a)==findpar(c)) return false;
        }
        return true;
        
    }
};