class MyCircularQueue {
public:
    vector<int> temp;
    int s;
    MyCircularQueue(int k) {
        temp.clear();
        s=k;
    }
    
    bool enQueue(int value) {
        if(temp.size()<s){
            temp.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(temp.size()>0){
           // reverse(temp.begin(),temp.end());
            temp.erase(temp.begin());
            //reverse(temp.begin(),temp.end());
            return true;
        }
        return false;
    }
    
    int Front() {
        if(temp.size()>0) return temp[0];
        return -1;
    }
    
    int Rear() {
        if(temp.size()>0) return temp[temp.size()-1];
        return -1;
    }
    
    bool isEmpty() {
        return temp.size()==0;
    }
    
    bool isFull() {
        return temp.size()==s;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */