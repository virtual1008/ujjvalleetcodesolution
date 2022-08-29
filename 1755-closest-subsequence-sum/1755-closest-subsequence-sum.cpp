class Solution {
public:
    void  rec(int i,int l,vector<int> & a,int sum,vector<int>& nums){
        if(i==l){
            a.push_back(sum);
            return;
        }
        rec(i+1,l,a,sum,nums);
        rec(i+1,l,a,sum+nums[i],nums);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> A,B;
        rec(0,n/2,A,0,nums);
        rec(n/2,n,B,0,nums);
        sort(A.begin(),A.end());
        int ans=INT_MAX;
        for(auto it:B){
            int d=goal-it;
            int c=lower_bound(A.begin(),A.end(),d)-A.begin();
            if(c>0) ans=min(ans,abs(d-A[c-1]));
            if(c<A.size()) ans=min(ans,abs(d-A[c]));
            
        }
        return ans;
    }
};