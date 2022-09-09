class Solution {
public:
    static bool cmp (vector<int> & a ,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        int maxi=INT_MIN;
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            if(v[i][1]<maxi){
                ans++;
            }
            maxi=max(maxi,v[i][1]);
        }
        return ans;
        
    }
};