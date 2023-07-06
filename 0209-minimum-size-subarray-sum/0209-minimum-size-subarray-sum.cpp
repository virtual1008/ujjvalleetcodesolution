class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=0;
        int i=0;
        int c=INT_MAX;
        while(i<nums.size() & ans<target){
            ans+=nums[i];
            i++;
            //cout<<ans<<"->"<<i<<endl;
        }
        if(ans>=target) c=min(c,i);
        if(i==1 & ans>=target) return 1;
        int j=0;
        while(i<nums.size()){
            if(ans>=target){
                c=min(c,i-j);
                ans-=nums[j];
                j++;
            }else{
                ans+=nums[i];
                i++;
            }
            //cout<<ans<<"->"<<i<<"->"<<j<<endl;
        }
        if(ans>=target) c=min(c,i-j);
        while(ans>=target && j<nums.size()){
            ans-=nums[j];
            j++;
            if(ans>=target){
                c=min(c,i-j);
            }
        }
        return c!=INT_MAX?c:0;
    }
};