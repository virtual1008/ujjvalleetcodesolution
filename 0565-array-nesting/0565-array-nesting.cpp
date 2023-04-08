class Solution {
public:
    void rec(vector<bool> & vis,int i,vector<int> &dist,int & len,vector<int> & nums ){
        if(vis[i]) {
           dist[i]=max(len,dist[i]);
            return;
        }
        vis[i]=1;
        len+=1;
        rec(vis,nums[i],dist,len,nums);
        dist[i]=len;
    }
    int arrayNesting(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        vector<int> dist(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                int len=0;
                rec(vis,i,dist,len,nums);   
            }
        }
        int maxi=0;
        for(auto it:dist){
            maxi=max(maxi,it);
        }
        return maxi;
    }
};