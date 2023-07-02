class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp(200+2,0);
        for(auto it:nums){
            temp[it+100]++;
        }
        nums.clear();
        for(int i=0;i<=201;i++){
            if(temp[i]>0){
                nums.push_back(i-100);
            }
        }
        return nums.size();
    }
};