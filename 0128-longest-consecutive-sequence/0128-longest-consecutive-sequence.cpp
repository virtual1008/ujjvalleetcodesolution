class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return nums.size();
        set<int> st;
        for(auto it:nums) st.insert(it);
        nums.clear();
        for(auto it:st) nums.push_back(it);
       // sort(nums.begin(),nums.end());
        int ans=1;
        int cnt=1;
        int i=1;
        int prev=nums[0];
        while(i<nums.size()){
            while(i<nums.size() && nums[i]-prev==1){
                prev=nums[i];
                i++;
                cnt++;
            }
            ans=max(ans,cnt);
            cnt=1;
            if(i<nums.size()) prev=nums[i];
            i++;
        }
        return ans;
    }
};