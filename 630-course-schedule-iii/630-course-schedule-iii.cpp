class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const vector<int>& a,vector<int>& b ){
            return a[1]<b[1];
        });
        priority_queue<int> pq;
        int time=0;
        for(auto it:courses){
           int a=it[0];
            int b=it[1];
            time+=a;
            pq.push(a);
            if(time>b){
                time-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};