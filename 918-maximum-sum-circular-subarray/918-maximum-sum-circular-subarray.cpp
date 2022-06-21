class Solution {
public:

int maxSubarraySumCircular(vector<int>& nums) {
    int total=0,minsum=nums[0],maxsum = nums[0],currmin =0,currmax=0;
    for(auto i:nums){
        total +=i;
        currmax = max(currmax+i,i);
        maxsum = max(maxsum,currmax);
        
        currmin = min(currmin+i,i);
        minsum = min (minsum,currmin);
    }
    if(maxsum>0){
        return max(maxsum,total-minsum);
    }else{
        return maxsum;
    }
}
};