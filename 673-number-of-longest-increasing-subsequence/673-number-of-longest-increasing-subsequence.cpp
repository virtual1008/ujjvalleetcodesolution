class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi=1;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(arr[pre]<arr[i]){
                    if(dp[pre]+1>dp[i]) {
                        dp[i]=1+dp[pre];
                        cnt[i]=cnt[pre];
                    }else if(dp[pre]+1==dp[i]){
                        cnt[i]+=cnt[pre];
                    }
                    if(dp[i]>maxi) maxi=dp[i];
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) ans+=cnt[i];
        }
        return ans;
    }
};