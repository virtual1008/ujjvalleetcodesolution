class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void rec(int i, vector<int> &nums){
        //int n=nums.size();
        int j=0;
        vector<int> temp;
        while((1<<j)<=i){
           if((1<<j)&i){
               temp.push_back(nums[j]);
           }
            j++;
        }
        st.insert(temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<(1<<n);i++){
            rec(i,nums);
        }
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};