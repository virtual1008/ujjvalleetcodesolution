class Solution {
public:
    map<string,bool> m;
    vector<bool> dp;
    bool rec(int i,string str){
        if(i==str.size()) return true;
        if(dp[i]) return dp[i];
        for(int j=i;j<str.size();j++){
            string s=str.substr(i,j-i+1);
            if(m[s] && s!=str && rec(j+1,str)) return dp[i]= true;
        }
        return dp[i]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto it:words) m[it]=true;
        vector<string> ans;
        for(auto it:words){
            dp=vector<bool>(words.size(),false);
            if(rec(0,it)) ans.push_back(it);
        }
        return ans;
    }
};