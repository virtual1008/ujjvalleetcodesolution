class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return {};
        vector<int> a(26,0);
        vector<int> ans;
        vector<int> b(26,0);
        for(int i=0;i<p.size();i++){
            a[p[i]-'a']++;
            b[s[i]-'a']++;
        }
        if(a==b) ans.push_back(0);
        for(int i=p.size();i<s.length();i++){
            b[s[i-p.size()] - 'a']--;
            b[s[i] - 'a']++;
            if(a==b) ans.push_back(i-p.length()+1);
        }
        return ans;
        
    }
};