class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int temp=0;
        for(int i=0;i<gain.size();i++){
            temp+=gain[i];
            //cout<<temp<<" ";
            ans=max(ans,temp);
        }
        return ans;
    }
};