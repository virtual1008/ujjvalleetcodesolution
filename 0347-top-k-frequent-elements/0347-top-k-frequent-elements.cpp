class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums) mp[it]++;
        vector<int> temp[100001];
        for(auto it:mp){
            temp[it.second].push_back(it.first);
        }
        vector<int> ans;
        int i=1e5;
        while(i>=0){
            auto it=temp[i];
            i--;
            if(it.size()>0){
                if(it.size()<=k){
                    k-=it.size();
                    for(auto e:it) ans.push_back(e);
                }else{
                    for(int j=0;j<k;j++){
                        ans.push_back(it[j]);
                    }
                    k=0;
                }
            }
            if(k==0) break;
        }
        return ans;
    }
};