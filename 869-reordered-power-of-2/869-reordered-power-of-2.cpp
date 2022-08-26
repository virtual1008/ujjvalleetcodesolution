class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str=to_string(n);
        sort(str.begin(),str.end());
        //vector<string> ans;
        for(int i=0;i<31;i++){
            int val=1<<i;
            string k=to_string(val);
            sort(k.begin(),k.end());
            if(str==k) return true;
        }
        return false;
        
    }
};