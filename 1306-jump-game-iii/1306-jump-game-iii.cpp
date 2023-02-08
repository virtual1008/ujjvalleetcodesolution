class Solution {
public:
    vector<int> dp;
    bool rec(int i,vector<int> &arr,vector<bool> vis){
        if(i<0 || i>=arr.size() || vis[i]) return false;
        if(arr[i]==0) return true;
        vis[i]=true;
        if(dp[i]!=-1) return dp[i];
        //cout<<i<<endl;
        //if(arr[i]==0) return false;
        //if(i<0 || i>=arr.size()) return false;
        return rec(i+arr[i],arr,vis)||rec(i-arr[i],arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis=vector<bool>(arr.size()+3,false);
        dp=vector<int>(arr.size()+3,-1);
        return rec(start,arr,vis);
    }
};