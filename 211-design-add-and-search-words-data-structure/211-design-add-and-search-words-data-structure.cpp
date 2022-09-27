struct Node{
    Node* links[26];
    bool flag=false;
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(auto it:word){
            if(!node->links[it-'a']){
                node->links[it-'a']=new Node();
            }
            node=node->links[it-'a'];
        }
        node->flag=true;
    }
    bool searchval(string &word,int i,Node* node){
        if(node==nullptr) node=root;
        if(i>=word.size()) return node->flag;
        for(;i<word.size();i++){
            if(word[i]!='.'){
                if(!node->links[word[i]-'a']) return false;
                return searchval(word,i+1,node->links[word[i]-'a']);
            }else{
                bool temp=false;
                for(auto it:node->links){
                    if(it==NULL) continue;
                    temp=temp|searchval(word ,i+1,it);
                }
                return temp;
            }
        }
        return false;
    }
    bool search(string word) {
        Node* node=root;
        return searchval(word,0,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */