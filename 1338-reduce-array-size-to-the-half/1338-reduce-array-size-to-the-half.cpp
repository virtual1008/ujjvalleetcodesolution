class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(auto it:arr) m[it]++;
        vector<int> v;
        for(auto it:m) v.push_back(it.second);
        sort(v.begin(),v.end(),greater<int>());
        int cnt=0;
        int k=0;
        for(auto it:v){
            cnt++;
            k+=it;
            if(k>=(arr.size()+1)/2) break;
            
        }
        return cnt;
    }
};