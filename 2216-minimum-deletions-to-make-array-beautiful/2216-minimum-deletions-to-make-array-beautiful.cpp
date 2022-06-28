class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if((i-cnt)%2==0){
                if(nums[i]==nums[i+1]){
                    cnt++;
                }
            }
        }
        if((n-cnt)%2!=0) cnt++;
        return cnt;
        
    }
};