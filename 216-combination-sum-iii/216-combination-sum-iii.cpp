class Solution {
public:
    void fun(vector<vector<int>> & ans,vector<int> v,int i,int sum,int n,int k){
        if(  i==10)
        {
            if(v.size()==k && sum==n)
            {
                    ans.push_back(v);
                
            }
            return ;
        }
        fun(ans,v,i+1,sum,n,k);
        v.push_back(i);
        sum+=i;
        
        fun(ans,v,i+1,sum,n,k);
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        fun(ans,v,1,0,n,k);
        return ans;
    }
};
