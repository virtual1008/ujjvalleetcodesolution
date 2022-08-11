class Solution {
public:
    vector<vector<int>> dp;
    int n;
    map<char,vector<int>> m;
    int rec(int i,string ring ,string key,int curr=0){
        if(i==key.size()) return 0;
        if(dp[i][curr]!=-1) return dp[i][curr];
        int d=1e5+1;
        for(auto it:m[key[i]]){
            d=min(d,min(abs(curr-it),n-abs(curr-it))+1+rec(i+1,ring,key,it));
        }
        return dp[i][curr]=d;
    }
    int findRotateSteps(string ring, string key) {
        n=ring.size();
        for(int i=0;i<n;i++){
            m[ring[i]].push_back(i);
        }
        int k=n;
        if(k<key.size()) k=key.size();
        dp=vector<vector<int>>(k+1,vector<int>(k+1,-1));
        return rec(0,ring,key);
    }
};