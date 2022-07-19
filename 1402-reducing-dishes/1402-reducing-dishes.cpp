class Solution {
public:
    int t[501][502];
    int solve(vector<int>& satisfaction,int time , int i){
        if(i>=satisfaction.size())
            return 0;
        
        if(t[i][time]!=-1)
            return t[i][time];
        int ans=solve(satisfaction,time,i+1);
        ans=max(ans,satisfaction[i]*time+solve(satisfaction,time+1,i+1));
        
        return t[i][time]=ans;
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(t,-1,sizeof(t));
        sort(satisfaction.begin(),satisfaction.end());
        int ans= solve(satisfaction,1,0);
        if(ans<0)
            return 0;
        
       return ans;
    }
};