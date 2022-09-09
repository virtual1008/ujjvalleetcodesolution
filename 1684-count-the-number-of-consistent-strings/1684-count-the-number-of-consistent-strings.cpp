class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> v(26,0);
        for(auto it:allowed){
            v[it-'a']=1;
        }
        int ans=0;
        for(auto it:words){
            vector<int> temp(26,0);
            for(auto ch:it){
                temp[ch-'a']=1;
            }
            bool flag=true;
            for(int i=0;i<26;i++){
                if(temp[i]==1 && v[i]==0){
                    flag=false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};