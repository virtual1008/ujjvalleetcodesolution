class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        priority_queue<pair<double,double>,vector<pair<double,double>>,greater<pair<double,double>>> pq;
        for(int i=0;i<wage.size();i++){
            double c=(double)wage[i];
            c/=(double)quality[i];
            pq.push({c,quality[i]});
        }
        priority_queue<double> q;
        double mini=INT_MAX;
        double ans=0;
        double prev=0;
        while(k--){
            auto it=pq.top();
            ans+=it.second;
            prev=it.first;
            q.push(it.second);
            pq.pop();
        }
        mini=min(ans*prev,mini);
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ans+=it.second;
            ans-=q.top();
            q.pop();
            q.push(it.second);
            prev=it.first;
            mini=min(ans*prev,mini);
        }
        return mini;
    }
};