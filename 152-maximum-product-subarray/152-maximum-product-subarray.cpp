class Solution {
public:
int maxProduct(vector<int>& nums) {

    int loc_max=1;
    int loc_min=1;
    int mul_max;
    int mul_min;
    int global_max=INT_MIN;
  
    for(int i=0;i<nums.size();i++){
        
        mul_max= loc_max*nums[i];
        mul_min =loc_min*nums[i];
        
        loc_max=std::max({mul_max,mul_min,nums[i]});
        loc_min=std::min({mul_max,mul_min,nums[i]});
        
            global_max=max(global_max,loc_max);
        
    }
    
    return global_max;

}
};