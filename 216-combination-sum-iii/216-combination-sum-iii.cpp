class Solution {
public:
    void fun(set<vector<int>> & ans,vector<int> v,int i,int sum,int n,int k){
        if(i==10){
            if(v.size()==k && sum==n){
            ans.insert(v);
        }
            return;
        }
        if(v.size()==k && sum==n){
            ans.insert(v);
        }
        v.push_back(i);
        sum+=i;
        fun(ans,v,i+1,sum,n,k);
        sum-=i;
        v.pop_back();
        fun(ans,v,i+1,sum,n,k); 
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ans;
        vector<int> v;
        fun(ans,v,1,0,n,k);
        vector<vector<int>> res;
        for(auto it:ans) res.push_back(it);
        return res;
    }
};
