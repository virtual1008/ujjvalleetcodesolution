class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> ti(n+1,INT_MAX);
        ti[0]=0;
        ti[k]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<times.size();j++)
            {
                int u=times[j][0];     
                int v=times[j][1];     
                int w=times[j][2];    
                if(ti[u]!=INT_MAX && ti[u]+w<ti[v])
                {
                    ti[v]=w+ti[u];
                }
            }
        }
        int maxi=INT_MIN;
        for(auto it:ti) maxi=max(maxi,it);
        if(maxi==INT_MAX) return -1;
        return maxi;
        
    }
};