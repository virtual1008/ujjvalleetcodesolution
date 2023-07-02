class Solution {
public:
    int ans=0;
    void rec(int i,vector<vector<int>> & requests,int l,vector<int> &temp){
        if(i==requests.size()){
            for(auto it:temp){
                if(it!=0) return;
            }
            ans=max(ans,l);
            return;
        }
        int a=requests[i][0];
        int b=requests[i][1];
        temp[a]--;
        temp[b]++;
        rec(i+1,requests,l+1,temp);
        temp[a]++;
        temp[b]--;
        rec(i+1,requests,l,temp);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> temp(n,0);
        rec(0,requests,0,temp);
        return ans;
    }
};