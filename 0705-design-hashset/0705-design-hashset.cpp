class MyHashSet {
public:
    vector<bool> temp;
    MyHashSet() {
        for(int i=0;i<=1000000;i++) temp.push_back(false); 
    }
    
    void add(int key) {
        temp[key]=true;
    }
    
    void remove(int key) {
        temp[key]=false;
    }
    
    bool contains(int key) {
        return temp[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */