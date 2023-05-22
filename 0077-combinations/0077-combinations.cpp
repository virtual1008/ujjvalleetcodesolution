class Solution {
public:
    vector<vector<int>> ans;
    void rec(int a,int c,int &n,vector<int> temp,int k){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=a;i<n;i++){
            if(c&(1<<i)){
                c^=(1<<i);
                temp.push_back(i+1);
                rec(i+1,c,n,temp,k);
                temp.pop_back();
                c|=(1<<i);
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        int c=0;
        for(int i=0;i<n;i++){
            c+=(1<<i);
        }
        //cout<<c;
        rec(0,c,n,temp,k);
        return ans;
    }
};