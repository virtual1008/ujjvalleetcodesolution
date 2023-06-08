struct Node{
     Node* links[26];
     bool flag=false;
     bool containkey(char c){
         return links[c-'a']!=NULL;
     }
     void put(char c,Node* node){
         links[c-'a']=node;
     }
     Node* get(char c){
         return links[c-'a'];
     }
};
class Solution {
public:
    Node* root=new Node();
    void insert(string &word){
        Node* node=root;
        for(auto it:word){
            if(!node->containkey(it)){
                node->put(it,new Node());
            }
            node=node->get(it);
        }
        node->flag=true;
    }
    void wordtrie(vector<string> & wordDict){
        for(auto word:wordDict){
            insert(word);
        }
    }
    bool search(string s){
        Node* node=root;
        for(auto it:s){
            if(!node->containkey(it)) return false;
            node=node->get(it);
        }
        return node->flag;
    }
    vector<vector<int>> dp;
    bool rec(int i,string &s,string t){
        if(i>=s.size()) return t.size()==0;
        t+=s[i];
        if(dp[i][i+t.size()]!=-1) return dp[i][i+t.size()];
        bool flag1=false;
        if(search(t)){
            flag1=rec(i+1,s,"");
        } 
        return dp[i][i+t.size()]=flag1 || rec(i+1,s,t);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         wordtrie(wordDict);
         bool ans=true;
         Node* node=root;
        dp=vector<vector<int>>(s.size(),vector<int>(2*s.size()+30,-1));
         ans=rec(0,s,"");
         return ans;
    }
};