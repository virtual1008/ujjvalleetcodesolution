class Solution {
public:
    vector<vector<int>> ans;
    void rec(int c,vector<int> temp,vector<int> &nums){
        if(nums.size()==temp.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(c&(1<<i)){
                c^=(1<<i);
                temp.push_back(nums[i]);
                rec(c,temp,nums);
                c|=(1<<i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            c+=(1<<i);
        }
        vector<int> temp;
        rec(c,temp,nums);
        return ans;
    }
};