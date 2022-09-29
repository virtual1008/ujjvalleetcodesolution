class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(auto it:arr){
            p.push({abs(it-x),it});
        }
        while(k--){
            auto it=p.top();
            p.pop();
            ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};