class Solution {
public:
    vector<vector<int>> ans;
    void rec(int i,int target,vector<int> &can ,vector<int> temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<can.size();j++){
            if(j>i && can[j]==can[j-1]) continue;
            if(can[j]>target) break;
            temp.push_back(can[j]);
            rec(j+1,target-can[j],can,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<int> temp;
        rec(0,target,can,temp);
        return ans;
    }
};