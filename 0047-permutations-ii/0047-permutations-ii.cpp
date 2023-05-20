class Solution {
public:
    set<vector<int>> ans;
    void rec(int c,vector<int> temp,vector<int>& nums){
        if(temp.size()==nums.size()){
            ans.insert(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(c&(1<<i)) continue;
            c|=(1<<i);
            temp.push_back(nums[i]);
            rec(c,temp,nums);
            c^=(1<<i);
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        int c=0;
        rec(c,temp,nums);
        vector<vector<int>> res;
        for(auto it:ans) res.push_back(it);
        return res;
    }
};