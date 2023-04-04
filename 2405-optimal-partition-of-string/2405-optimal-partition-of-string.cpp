class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        unordered_map<int,int> mp;
        for(auto it:s){
            if(mp[it]==1){
                ans++;
                mp.clear();
            }
            mp[it]++;
        }
        if(mp.size()>0) ans++;
        return ans;
    }
};