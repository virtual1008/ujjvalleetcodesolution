class Solution {
public:
    vector<vector<int>> ans;
    void rec(int i,vector<int>& nums,set<vector<int>> & st){
        int n=nums.size();
        int j=0;
        vector<int> temp;
        while((1<<j)<=i){
            int val=1<<j;
            if(val&i) temp.push_back(nums[j]);
            j++;
        }
        st.insert(temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<(1<<n);i++){
            rec(i,nums,st);
        }
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};