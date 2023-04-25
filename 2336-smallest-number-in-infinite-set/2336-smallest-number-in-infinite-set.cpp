class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        st.clear();
        for(int i=1;i<=1001;i++) st.insert(i);
    }
    
    int popSmallest() {
        int c=*st.begin();
        if(st.size()) st.erase(st.begin());
        return c;
    }
    
    void addBack(int num) {
       st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */