class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto it:nums) m[it]++;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int rem=k-nums[i];
            if(rem==nums[i]){
               if(m[rem]>1){
                   ans+=(m[rem]/2);
                   m[rem]%=2;
                   continue;
               }else continue; 
            }
            if(m[rem]>0){
                int c=min(m[rem],m[nums[i]]);
                ans+=c;
                m[rem]-=c;
                m[nums[i]]-=c;
            }
        }
        return ans;
    }
};