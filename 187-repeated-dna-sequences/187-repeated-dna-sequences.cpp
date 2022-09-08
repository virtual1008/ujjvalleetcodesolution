class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string,int> mp;
        if(s.size()<=10) return ans;
        for(int i=0;i<=s.size()-10;i++){
            string str=s.substr(i,10);
            mp[str]++;      
        }
        for(auto it:mp){
            if(it.second>1) ans.push_back(it.first);
        }
        return ans;
    }
};