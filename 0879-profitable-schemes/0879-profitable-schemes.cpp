class Solution {
public:
    int mod = (int)1e9 + 7; 
    vector<vector<vector<int>>>dp;   
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp.resize(102, vector<vector<int>>(n + 2, vector<int>(group.size(), -1)));
        return rec(n,minProfit,group,profit,0,0,0);
    }
    int rec(int &n,int &mp,vector<int>&group,vector<int> & profit,int cp,int people,int i){
        if(people>n) return 0;
        cp=min(cp,mp);
        if(i==group.size()){
            if(cp>=mp) return 1;
            return 0;
        }
        if(dp[cp][people][i]!=-1) return dp[cp][people][i];
        int take=rec(n,mp,group,profit,cp+profit[i],people+group[i],i+1);
        int not_take=rec(n,mp,group,profit,cp,people,i+1);
        
        return dp[cp][people][i]=(take+not_take)%mod;
        
    }
};