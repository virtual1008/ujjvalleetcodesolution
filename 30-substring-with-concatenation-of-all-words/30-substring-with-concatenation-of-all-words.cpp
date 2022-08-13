class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size();
        int m=words[0].size();
        int len=n*m;
        vector<int> ans;
        if(len>s.size()) return ans;
        for(int i=0;i<=s.size()-len;i++){
             map<string,int> mp;
             for(auto it:words) mp[it]++;
             int k=0;
            for(k=0;k<n;k++){
                string str=s.substr(i+k*m,m);
                if(mp[str]==0) break;
                else mp[str]--;
            }
            if(k==n) ans.push_back(i);
        }
        return ans;
    }
};