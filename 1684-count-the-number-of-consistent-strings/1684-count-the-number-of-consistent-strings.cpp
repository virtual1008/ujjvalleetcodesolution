class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        int cnt=0;
        for(auto it:allowed){
            cnt|=(1<<(it-'a'));
        }
        for(auto it:words){
            bool flag=true;
            for(auto ele:it){
                if(!(cnt & (1<<(ele-'a')))){
                    flag=false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};