class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> temp;
        for(int i=0;i<nums1.size();i++){
            temp.push_back({nums1[i],i});
        }
        sort(temp.begin(),temp.end(),greater<pair<int,int>> ());
        long long sum=0;
        long long ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<k;i++){
            sum+=temp[i].first;
            pq.push({nums2[temp[i].second],temp[i].second});
        }
        ans=sum;
        auto c=pq.top();
        ans*=(c.first);
        for(int i=k;i<nums1.size();i++){
            auto c=pq.top();
            pq.pop();
            sum-=nums1[c.second];
            sum+=temp[i].first;
            pq.push({nums2[temp[i].second],temp[i].second});
            long long ty=sum;
            auto a=pq.top();
            ty*=(a.first);
            ans=max(ans,ty);
        }
        return ans;
    }
};