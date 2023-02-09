class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        map<int,set<string>> mp;
        for(auto it:ideas){
            mp[it[0]-'a'].insert(it.substr(1));
        }
        long long ans=0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                int cnt=0;
                for(auto it:mp[j]){
                    if(mp[i].find(it)!=mp[i].end()) cnt++;
                }
                ans+=2*(mp[i].size()-cnt)*(mp[j].size()-cnt);
            }
        }
        //ans*=2;
        return ans;
    }
};