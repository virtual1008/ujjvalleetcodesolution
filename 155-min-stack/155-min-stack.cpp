class MinStack {
public:
    stack<int>s;
    priority_queue<int,vector<int>,greater<int>>q;
    map<int,int>m;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        q.push(val);
        m[val]++;
    }
    
    void pop() {
        int val=s.top();
        m[val]--;
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        
        stack<int>temp;
        int mi=INT_MAX;
        while(1)
        {
            int val=q.top();
            if(m[val]>0)
                return val;
            q.pop();
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */