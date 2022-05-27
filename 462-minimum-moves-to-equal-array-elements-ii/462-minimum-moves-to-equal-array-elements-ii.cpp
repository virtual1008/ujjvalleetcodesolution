class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long >pre(n,0);
        long long  sum=0;
        pre[0]=nums[0];
        
        for(int i=1;i<n;i++)
            pre[i]=nums[i]+pre[i-1];
        
        sum=pre[n-1];
        long long  ans=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            long long  l=i;
            long long  r=n-(i+1);
            if(i==0)
            {
                long long  acu=r*(nums[i]);
                long long  tot=sum-pre[i];
                ans=min(ans,abs(acu-tot));
            }
            else if(i==n-1)
            {
                long long  acu=l*(nums[i]);
                long long  tot=pre[i-1];
                ans=min(ans,abs(acu-tot));
            }
            else
            {
                long long  acuu=r*(nums[i]);
                long long  toto=sum-pre[i];
                 long long  acu=l*(nums[i]);
                long long  tot=pre[i-1];
                ans=min(ans,abs(acu-tot)+abs(acuu-toto)); 
            }
        }
        return ans;
    }
};