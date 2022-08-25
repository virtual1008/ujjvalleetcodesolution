class Solution {
public:
    bool canConstruct(string str1, string str2) {
        vector<int> ans(26,0);
       // for(int i=0;i<26;i++) ans[i]=0;
        for(char c : str2){
            ans[c-'a']++;
        }
        for(char c : str1){
            ans[c-'a'] -= 1;
            if(ans[c-'a'] < 0) return false;
        }
        
        return true;
    }
};