class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(auto it:m){
             int x=it.first;
             int y=it.second;
             pq.push({y,x});
        }
        vector<int> ans;
        while(!pq.empty() && k--){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};