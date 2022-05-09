class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int l=i+1;
                int r=nums.size()-1;
                int sum=0-nums[i];
                while(l<r){
                    if(nums[l]+nums[r]==sum){
                        vector<int> temp;
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        temp.push_back(nums[i]);
                        ans.push_back(temp);
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;
                        l++;
                        r--;
                        
                    }else if(nums[l]+nums[r]<sum) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
}; 