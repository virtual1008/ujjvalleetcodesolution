class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<=2) return abs(nums[0]-nums[nums.size()-1]);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto it:nums){
            maxi=max(maxi,it);
            mini=min(mini,it);
        }
        int n=nums.size();
        int bucketsize=ceil((1.0)*(maxi-mini)/(nums.size()-1));
        if(bucketsize==0) return 0;
        vector<int> maxivect(n,INT_MIN);
        vector<int> minivect(n,INT_MAX);
        for(int i=0;i<n;i++){
            int temp=(nums[i]-mini)/bucketsize;
            maxivect[temp]=max(maxivect[temp],nums[i]);
            minivect[temp]=min(minivect[temp],nums[i]);
        }
        int ans=0;
        int prev=mini;
        for(int i=0;i<n;i++){
            if(minivect[i]==INT_MAX) continue;
            ans=max(ans,minivect[i]-prev);
            prev=maxivect[i];
        }
        //for(auto it:maxivect) cout<<it<<" ";
       // cout<<"\n";
        return ans;
    }
};