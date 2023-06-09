struct Node{
    Node *links[26];
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
class StreamChecker {
public:
    Node* root=new Node();
    string check="";
    StreamChecker(vector<string>& words) {
        for(auto it:words){
            Node* node=root;
            for(int i=it.size()-1;i>=0;i--){
                char e=it[i];
                if(!node->containkey(e)){
                    node->put(e,new Node());
                }
                node=node->get(e);
            }
            node->flag=true;
        }
        check="";
    }
    
    bool query(char letter) {
       check+=letter;
        Node* node=root;
       for(int i=check.size()-1;i>=0;i--){
           if(!node->containkey(check[i])) return false;
           node=node->get(check[i]);
           if(node->flag) return true;;
       }
       return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */