class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i=1;i<s.length();i++){
            s[0]^=s[i];
        }
        for(int i=0;i<t.length();i++){
            s[0]^=t[i];
        }
        return s[0];
    }
};