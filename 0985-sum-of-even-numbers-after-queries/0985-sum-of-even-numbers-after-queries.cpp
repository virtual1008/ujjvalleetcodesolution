class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum=0;
        for(auto it:nums){
            if(it%2==0) sum+=it;
        }
        for(auto it:queries){
            int value=it[0];
            int index=it[1];
            int temp=nums[index];
            if(temp%2==0) sum-=temp;
            temp+=value;
            nums[index]=temp;
            if(temp%2==0) sum+=temp;
            ans.push_back(sum);
        }
        return ans;
    }
};