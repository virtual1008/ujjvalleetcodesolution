class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> v(26,0);
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(i-1>=0 &&(s[i]-s[i-1]==1 || s[i-1]-s[i]==25)){
                cnt++;
            }else{
                cnt=1;
            }
            v[s[i]-'a']=max(v[s[i]-'a'],cnt);
        }
        int c=0;
        for(auto it:v) c+=it;
        return c;
    }
};