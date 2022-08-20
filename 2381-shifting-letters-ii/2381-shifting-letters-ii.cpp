class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>&v) {
        int n=s.size();
        n+=1;
        vector<int> ans(n,0);
        for(auto it:v){
            if(it[2]){
                ans[it[0]]++;
                ans[it[1]+1]--;
            }else{
                ans[it[0]]--;
                ans[it[1]+1]++;
            }
        }
        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }
        for(int i=0;i<n;i++){
            char c=s[i];
            if(ans[i]>0){
                ans[i]%=26;
                while(ans[i]--){
                    if(c=='z') c='a';
                    else
                    c++;
                }
            }else{
                ans[i]*=-1;
                ans[i]%=26;
                while(ans[i]--){
                    if(c=='a') c='z';
                    else
                    c--;
                }
            }
            s[i]=c;
        }
        return s;
    }
};