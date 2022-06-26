class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n,-1);
        return rec(0,n,days,costs,dp);
    }
    int rec(int i,int n,vector<int> days,vector<int> costs,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int day1=costs[0]+rec(i+1,n,days,costs,dp);
        int j;
        for(j=i;j<n&& days[j]<days[i]+7;j++);
        int day7=costs[1]+rec(j,n,days,costs,dp);
        for(j=i;j<n&& days[j]<days[i]+30;j++);
        int day30=costs[2]+rec(j,n,days,costs,dp);
        return dp[i]=min({day1,day7,day30});
            
    }
};