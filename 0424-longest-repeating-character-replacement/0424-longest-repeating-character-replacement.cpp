class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        unordered_set<char> st;
        for(auto it:s) st.insert(it);
        for(auto C:st){
            int cnt=0;
            int l=0;
            for(int i=0;i<s.size();i++){
                if(s[i]!=C) cnt++;
                while(cnt>k){
                    if(s[l]!=C) cnt--;
                    l++;
                }
                ans=max(ans,i-l+1);
            }
        }
        return ans;
    }
};