class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& v) {
        vector<int> ans,result;
        
        for(int i=0;i<v.size();i++){
            auto it=(upper_bound(ans.begin(),ans.end(),v[i]))-ans.begin();
            result.push_back(it+1);
            if(it==ans.size()) ans.push_back(v[i]);
            else ans[it]=v[i];
        }
        return result;
    }
};