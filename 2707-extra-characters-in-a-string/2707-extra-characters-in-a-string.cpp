struct Node{
     Node* links[26];
     bool flag=false;
     bool containkey(char c){
         return links[c-'a']!=NULL;
     }
     void put(char c,Node * node){
         links[c-'a']=node;
     }
     Node* get(char c){
         return links[c-'a'];
     }
};
class Solution {
public:
    Node* root=new Node();
    void insert(vector<string> & dict){
        for(auto it:dict){
            Node* node=root;
            for(auto c:it){
                if(!node->containkey(c)){
                    node->put(c,new Node());
                }
                node=node->get(c);
            }
            node->flag=true;
        }
    }
    bool search(string s){
        Node* node=root;
        for(auto e:s){
            if(!node->containkey(e)) return false;
            node=node->get(e);
        }
        return node->flag;
    }
    vector<vector<int>> dp;
    int rec(int i,string &s ,string t){
        if(i>=s.size()){
            if(search(t)) return 0;
            return t.size();
        }
        t+=s[i];
        if(dp[i][i+t.size()]!=-1) return dp[i][i+t.size()];
        int take=1e3;
        if(search(t)){
           // take=min(rec(i+1,s,""),rec(i+1,s,t));
            take=rec(i+1,s,"");
        }
        int ntake=t.size()+rec(i+1,s,"");
        int val=min(rec(i+1,s,t),ntake);
        return dp[i][i+t.size()]=min(val,take);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
       insert(dictionary);
        dp=vector<vector<int>>(s.size(),vector<int>(2*s.size()+4,-1));
       return rec(0,s,"");
    }
};