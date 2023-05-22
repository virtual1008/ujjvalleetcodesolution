class Solution {
public:
    vector<vector<int>> ans;
    void rec(int a,int &k,int &n,vector<int> temp){
        if(temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        for(int i=a;i<=n;i++){
            temp.push_back(i);
            rec(i+1,k,n,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        rec(1,k,n,temp);
        return ans;
    }
};