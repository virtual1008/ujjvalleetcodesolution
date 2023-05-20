class Solution {
public:
    vector<vector<int>> ans;
    void rec(map<int,bool> mp,vector<int> temp,vector<int>&nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[i]==false){
                temp.push_back(nums[i]);
                mp[i]=true;
                rec(mp,temp,nums);
                mp[i]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        map<int,bool> vis;
        rec(vis,temp,nums);
       return ans;
    }
};