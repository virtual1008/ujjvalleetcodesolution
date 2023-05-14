class Solution {
public:
    unordered_map<int,int> mp;
    int rec(int k,int mask,vector<int> & nums,int n){
        if(k==0) return 0;
        int temp=k+mask*10;
        if(mp.find(temp)!=mp.end()) return mp[temp];
        int ans=0;
        for(int i=0;i<n;i++){
            if((1<<i)&(mask)){
                for(int j=0;j<n;j++){
                    if(i!=j &&((1<<j)&mask)){
                        int left=k*__gcd(nums[i],nums[j])+rec(k+1,(mask^(1<<i)^(1<<j)),nums,n);
                        ans=max(ans,left);
                    }
                }
            }
        }
        return mp[temp]=ans;
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        return rec(1,(1<<n)-1,nums,n);
    }
};