class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    vector<int> vec;
    vec.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(nums[i]>=vec[vec.size()-1]) vec.push_back(nums[i]);
        else{
            int l=0,r=vec.size()-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(vec[mid]>nums[i]){
                    r=mid-1;
                }else l=mid+1;
            }
            vec[l]=nums[i];
        }
    }
    return vec.size()+1>=nums.size();
        
    }
};