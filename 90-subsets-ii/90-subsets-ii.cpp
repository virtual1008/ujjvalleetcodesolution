class Solution {
public:
    set<vector<int>> st;
    void dfs(vector<int> &nums,int i,vector<int> temp){
        if(i>=nums.size()){
            st.insert(temp);
            return ;
        }
        dfs(nums,i+1,temp);
        temp.push_back(nums[i]);
        dfs(nums,i+1,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        dfs(nums,0,temp);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};