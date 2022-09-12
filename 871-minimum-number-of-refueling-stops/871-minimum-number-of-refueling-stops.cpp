class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       priority_queue<int> pq;
       int i=0;
        int ans=0;
       while(startFuel<target){
             while(i<stations.size() && startFuel>=stations[i][0]){
                 pq.push(stations[i][1]);
                 i++;
             }
             if(pq.empty()) return -1;
             startFuel+=pq.top();
           ans++;
             pq.pop();
       } 
        return ans;
    }
};