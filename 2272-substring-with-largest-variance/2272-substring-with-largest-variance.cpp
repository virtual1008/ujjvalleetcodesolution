class Solution {
public:
    int rec(char a,char b,string &s){
        int cnt_a=0,cnt_b=0;
        int ans=0;
        for(auto it:s){
            if(it==a) cnt_a++;
            else if(it==b) cnt_b++;
            else continue;
            if(cnt_b>0) ans=max(ans,cnt_a-cnt_b);
            else if(cnt_b==0) ans=max(ans,cnt_a-1);
            if(cnt_a<cnt_b){
                cnt_a=0;
                cnt_b=0;
            }
        }
        return ans;
    }
    int largestVariance(string s) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        int ans=0;
        for(char a='a';a<='z';a++){
            for(char b='a';b<='z';b++){
                if(a!=b && mp[a]!=0 && mp[b]!=0){
                    ans=max(ans,rec(a,b,s));
              }
            }
        }
        return ans;
    }
};