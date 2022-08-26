bool compare(vector<int> &int1,vector<int> &int2){
        return int2[1]>int1[1];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int ans=1;
        int l=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=l){
                l=intervals[i][1];
                ans++;
            }
        }
        return intervals.size()-ans;
    }
};