class Solution {
public:
    map<pair<int ,int>,int> dp;
    int rec(int i,int prev,vector<int> &arr1,vector<int> &arr2){
        if(i==arr1.size()) return 0;
        if(dp.find({i,prev})!=dp.end()) return dp[{i,prev}];
        int pick=1e6,not_pick=1e6;
        if(arr1[i]>prev){
            not_pick=rec(i+1,arr1[i],arr1,arr2);
        }
        int check=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(check!=arr2.size()){
            pick=rec(i+1,arr2[check],arr1,arr2);
        }
        return dp[{i,prev}]=min(pick+1,not_pick);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int ans=rec(0,INT_MIN,arr1,arr2);
        return ans>=1e6?-1:ans;
    }
};