class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto it:words){
            int c=0;
            if(mp[it]!=0) continue;
            for(int i=0;i<it.size();i++){
                c|=(1<<(it[i]-'a'));
            }
            mp[it]=c;
            
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            int c1=it->second;
            string s1=it->first;
            for(auto e=mp.begin();e!=it;e++){
                string s2=e->first;
                int c2=e->second;
                if(c1&c2) continue;
                int k=s1.size();
                k*=s2.size();
                if(ans<k) ans=k;
                //ans=max(ans,(s1.size())*(s2.size()));
            }
        }
        return ans;
    }
};