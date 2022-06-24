class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long tsum=0;
        for(auto it:target) pq.push(it),tsum+=it;
        while(pq.top()!=1){
            long long c=pq.top();
            pq.pop();
            tsum-=c;
            if(tsum<=0 || tsum>=c) return false;
            c=c%tsum;
            if(c>0)pq.push(c);
            else pq.push(tsum);
            tsum+=c;
        }
        return true;
    }
};