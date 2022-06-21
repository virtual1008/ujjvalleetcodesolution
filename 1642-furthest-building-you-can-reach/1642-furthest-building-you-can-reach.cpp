class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
       priority_queue<int, vector<int>, greater<int>> pq;
        int n=heights.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            int diff=heights[i]-heights[i-1];
            if(diff>0){
                pq.push(diff);
                if(pq.size()>ladders){
                   cnt+=pq.top();
                   pq.pop();
                }
                if(cnt>bricks) return i-1;
            }
        }return n-1;
    }
};