class Solution {
public:
    const int mod=1e9+7;
    int countPairs(vector<int>& a) {
        vector<int> v;
        int n=a.size();
        int maxi=*max_element(a.begin(),a.end());
        for(int i=1;i<=2*maxi;i*=2) v.push_back(i);
        int ans=0;
        map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            for(auto it:v){
                if(it-a[i]>=0) ans=(ans+mp[it-a[i]])%mod;
            }
            mp[a[i]]++;
        }
        return ans;
    }
};