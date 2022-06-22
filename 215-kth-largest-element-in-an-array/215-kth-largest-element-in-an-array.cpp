class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int> q;
      for(auto i:nums) q.push(i);
        int c;
        while(k--){
            c=q.top();
            q.pop();
        }
        return c;
    }
};