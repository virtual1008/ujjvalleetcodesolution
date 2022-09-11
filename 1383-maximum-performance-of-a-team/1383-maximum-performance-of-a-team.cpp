class Solution{
public:
    const int mod = (int)1e9 + 7;
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k){
      priority_queue<int, vector<int>, greater<int>> pq;
      vector<pair<int, int>> v;
      for (int i = 0; i < n; i++){
        v.push_back({efficiency[i], speed[i]});
      }
      sort(v.rbegin(), v.rend()); 
      long totSpeed = 0, ans = 0;
      for (int i = 0; i < n; i++) {
        int currEff = v[i].first;
        int currSpeed = v[i].second;
        if (pq.size() == k) {
          totSpeed -= pq.top();
          pq.pop();
        }
        pq.push(currSpeed);
        totSpeed += currSpeed; 
        ans = max(ans, totSpeed * currEff); 
      }class Solution {
public:
    int maxPerformance(int n, vector<int>&a, vector<int>& b, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({b[i],a[i]});
            
            
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        long long ans=0;
        long long sum=0;
        int mod=1e9+7;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            sum+=(v[i].second);
            if(pq.size()==k){
                sum-=(pq.top());
                pq.pop();
            };
            ans=max(ans,((sum)*(v[i].first)));
            pq.push(v[i].second);
            //cout<<sum*v[i].first<<" ";
        }
        return ans;
    }
};
      return ans % mod;
    }
};
