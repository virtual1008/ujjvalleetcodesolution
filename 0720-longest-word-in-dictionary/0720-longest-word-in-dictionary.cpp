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
    void insert(vector<string>& words){
        for(auto it:words){
            Node* node=root;
            for(auto e:it){
                if(!node->containkey(e)){
                    node->put(e,new Node());
                }
                node=node->get(e);
            }
            node->flag=true;
        }
    }
    string longestWord(vector<string>& words) {
          insert(words);  
          int mini=0;
          string ans="";
          for(auto it:words){
              Node* node=root;
              string str;
              for(auto e:it){
                  node=node->get(e);
                  str+=e;
                  if(node->flag){
                      if(str.size()>mini){
                          mini=str.size();
                          ans=str;
                      }else if(str.size()==mini){
                          ans=min(ans,str);
                      }
                  }else{
                      break;
                  }
              }
          }
        return ans;
    }
};