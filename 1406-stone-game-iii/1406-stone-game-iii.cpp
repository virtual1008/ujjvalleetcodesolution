class Solution {
public:
    int n;
    int dp[50001];
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        int ans=fun(0,stoneValue);
        return ans==0?"Tie":ans>0?"Alice":"Bob";
    }
  int  fun(int i,vector<int>& s){
        if(i>=n) return 0;
      if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN,sum=0;
       for(int j=0;j<3;j++){
          
           if(i+j<n){
                sum+=s[i+j];
               ans=max(ans,sum-fun(i+j+1,s));
           } else break;
       }
        return dp[i]= ans;
       
    }
};