class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> umap={{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
        stack<char> q;
        for(int i=0;i<s.length();i++){
            if(umap[s[i]]>0){
                q.push(s[i]);
            }else if(umap[s[i]]<0 && q.empty()) return false;
            else{
                char c=q.top();
                if(umap[c]+umap[s[i]]!=0){
                    return false;
                }
                q.pop();
                
            }
        }
        return q.empty();
    }
};