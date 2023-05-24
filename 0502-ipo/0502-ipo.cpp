class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        priority_queue<int,vector<int>> q;
        for(int i=0;i<capital.size();i++){
            pq.push({capital[i],profits[i]});
        }
        int ans=w;
        while(!pq.empty() && k>0){
              while(!pq.empty() && ans>=pq.top().first){
                  auto it=pq.top();
                  pq.pop();
                  q.push(it.second);
              }
              if(q.size()==0){
                  break;
              }else{
                  ans+=q.top();
                  q.pop();
                  k--;
              }
        }
        while(!q.empty() && k>0){
            ans+=q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};